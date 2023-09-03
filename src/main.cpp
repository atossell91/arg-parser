#include <iostream>

#include "ArgParser.h"

void debug_printInfo(AntSpace::ArgData data);

int main(int argc, const char* argv[]) {
    AntSpace::ArgParser parser;

    parser.AddSubCommandFunction([&](AntSpace::ArgData data){
        std::cout << "The sub command ('" << data.Name << "') is running" << std::endl;
    });

    parser.DisableSubCommand();

    parser.AddAction("name", debug_printInfo);
    parser.AddAction("bar", debug_printInfo);

    parser.ParseArgs(argc, argv);

    return 0;
}

void debug_printInfo(AntSpace::ArgData data) {
    std::cout << "Name is: " << data.Name << std::endl;
    for (auto str : data.Data) {
        std::cout << str << std::endl;
    }
    std::cout << "-----  -----  -----" << std::endl << std::endl;
}
