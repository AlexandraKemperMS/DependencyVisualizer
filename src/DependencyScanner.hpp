#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <filesystem>

class DependencyScanner {
public:
    using Graph = std::unordered_map<std::string, std::unordered_set<std::string>>;
    static Graph scan(const std::filesystem::path& root);
};
