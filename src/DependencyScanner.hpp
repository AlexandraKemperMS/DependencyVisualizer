#pragma once
#include <filesystem>
#include <map>
#include <set>
#include <string>

class DependencyScanner {
public:
    using DependencyMap = std::map<std::string, std::set<std::string>>;
    static DependencyMap scan_directory(const std::filesystem::path& root_dir);
};
