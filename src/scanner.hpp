#pragma once
#include <string>
#include <vector>
#include <unordered_map>

// Scans a directory and parses #include relationships
class DependencyScanner {
public:
    // Map: file -> set of included files
    using DependencyMap = std::unordered_map<std::string, std::vector<std::string>>;

    // Recursively scan directory for .cpp/.hpp files and parse includes
    static DependencyMap scan_directory(const std::string& root_dir);
};
