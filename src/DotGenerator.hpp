#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>

class DotGenerator {
public:
    using DependencyGraph = std::unordered_map<std::string, std::unordered_set<std::string>>;
    static void write_dot(const DependencyGraph& graph, const std::string& out_path);
};
