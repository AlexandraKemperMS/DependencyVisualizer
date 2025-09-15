#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>

class GraphWriter {
public:
    using DependencyMap = std::unordered_map<std::string, std::unordered_set<std::string>>;
    static void write_dot(const std::string& filename, const DependencyMap& deps);
};
