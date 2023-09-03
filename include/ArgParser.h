#pragma once

#include <map>
#include <functional>
#include <string>

#include "ArgData.h"

namespace AntSpace {
    class ArgParser
    {
    private:
        using workFunc = std::function<void(ArgData)>;

        std::map<std::string, workFunc> actions;
    public:
        bool IsArg(const char* arg);
        void AddAction(const std::string& name, workFunc func) { actions.emplace(name, func); }

        int SkipHyphens(const char*);

        //  Returns -1 if unsuccessful
        int GetArg(int arrIndex, int arrSize, const char* args[], ArgData& argData);
        
        bool ParseArgs(int, const char*[]);
    };
};
