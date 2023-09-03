#include <iostream>

#include "ArgParser.h"

int main(int argc, const char* argv[]) {
    AntSpace::ArgParser parser;

    parser.AddAction("foo", [&](AntSpace::ArgData d){});
    parser.AddAction("bar", [&](AntSpace::ArgData d){});

    parser.ParseArgs(argc, argv);

    return 0;
}