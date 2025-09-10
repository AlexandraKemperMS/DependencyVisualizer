#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class DotWriter {
public:
    // Writes a DOT file from the dependency map
    static void write_dot(const std::string& out_path, const std::unordered_map<std::string, std::vector<std::string>>& deps);
};
