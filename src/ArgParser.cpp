#include "ArgParser.h"

#include <string>
#include <iostream>

#include "ArgData.h"

using namespace AntSpace;

bool ArgParser::IsArg(const char* arg) {
    return arg[0] == '-';
}

int ArgParser::SkipHyphens(const char* str) {
    for (int n = 0; str[n] != '\0'; ++n) {
        if (str[n] == '-') continue;
        else return n;
    }

    return -1;
}

int ArgParser::GetArg(int ArrIndex, int ArrSize, const char* Args[], ArgData& Data) {
    
    const char* arg = Args[ArrIndex];

    int nameStart = SkipHyphens(arg);
    Data.Name = &arg[nameStart];

    ++ArrIndex;

    for (; ArrIndex < ArrSize && !IsArg(Args[ArrIndex]); ++ArrIndex) {
        Data.Data.push_back(Args[ArrIndex]);
    }

    return ArrIndex;
}

bool ArgParser::ParseArgs(int argc, const char* argv[]) {

    if (argc < 2) {
        std::cout << "No arguments found" << std::endl;
        return false;
    }

    int index = 1;
    if (useSubCommand) {

        if (IsArg(argv[index])) {
            std::cout << "Sub-command error: First command shouldn't start with '-'" << std::endl;
            return false;
        }

        ArgData subCommandData;
        index = GetArg(index, argc, argv, subCommandData);
        subCommandFunction(subCommandData);
    }

    while (index < argc) {
        ArgData data;

        const char* arg = argv[index];

        if (arg[0] != '-') {
            std::cout << "Parse error: No preceding '-'" << std::endl;
            return false;
        }

        int argResult = GetArg(index, argc, argv, data);

        if (argResult < 0) {
            std::cout << "Parse Error: "
            << "Arg, \'" << arg << "\'"
            << std::endl;
            return false;
        }

        index = argResult;

        if (actions.find(data.Name) != actions.end()) {
            actions[data.Name](data);
        }
    }
    
    return true;
}
