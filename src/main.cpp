#include <iostream>

#include "ArgParser.h"

int main(int argc, const char* argv[]) {
    AntSpace::ArgParser parser;

    parser.AddSubCommandFunction([&](AntSpace::ArgData data){
        std::cout << "The sub command is running" << std::endl;
    });

    parser.EnableSubCommand();

    parser.AddAction("foo", [&](AntSpace::ArgData d){});
    parser.AddAction("bar", [&](AntSpace::ArgData d){});

    parser.ParseArgs(argc, argv);

    return 0;
}