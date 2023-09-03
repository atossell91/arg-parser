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

        workFunc subCommandFunction;
        std::map<std::string, workFunc> actions;
        bool useSubCommand = true;

    public:
        bool IsArg(const char* arg);
        void AddAction(const std::string& name, workFunc func) { actions.emplace(name, func); }

        void EnableSubCommand() { useSubCommand = true; }
        void DisableSubCommand() { useSubCommand = false; }
        void AddSubCommandFunction(workFunc function) { subCommandFunction = function; }

        int SkipHyphens(const char*);

        //  Returns -1 if unsuccessful
        int GetArg(int arrIndex, int arrSize, const char* args[], ArgData& argData);
        
        bool ParseArgs(int, const char*[]);
    };
};
