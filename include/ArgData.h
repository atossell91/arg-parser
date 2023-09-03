#pragma once

#include <string>
#include <vector>

namespace AntSpace
{
    struct ArgData {
        std::string Name;
        std::vector<std::string> Data;

        bool HasData() const { return Data.size() > 0; }
    };
} // namespace AntSpace

