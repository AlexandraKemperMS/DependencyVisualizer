#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <filesystem>

class DependencyScanner {
public:
    using DependencyMap = std::unordered_map<std::string, std::unordered_set<std::string>>;
    static DependencyMap scan_directory(const std::filesystem::path& root);
};
