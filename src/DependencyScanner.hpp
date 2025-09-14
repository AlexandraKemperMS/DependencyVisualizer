#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class DependencyScanner {
public:
    using DependencyGraph = std::unordered_map<std::string, std::unordered_set<std::string>>;
    DependencyScanner() = default;
    DependencyGraph scan(const std::string& root_dir);
private:
    void scan_file(const std::string& file_path, DependencyGraph& graph);
    void scan_directory(const std::string& dir_path, DependencyGraph& graph);
    static bool is_cpp_file(const std::string& filename);
    static std::string extract_include(const std::string& line);
};
