#include "DependencyScanner.hpp"
#include <filesystem>
#include <fstream>
#include <regex>

namespace fs = std::filesystem;

bool DependencyScanner::is_cpp_file(const std::string& filename) {
    static const std::vector<std::string> exts = {".cpp", ".hpp", ".h", ".cxx", ".cc", ".hxx"};
    for (const auto& ext : exts) {
        if (filename.size() >= ext.size() && filename.substr(filename.size() - ext.size()) == ext)
            return true;
    }
    return false;
}

std::string DependencyScanner::extract_include(const std::string& line) {
    static const std::regex include_regex(R"(^\s*#\s*include\s*[<"]([^"]+)[">])");
    std::smatch match;
    if (std::regex_search(line, match, include_regex)) {
        std::string inc = match[1];
        auto pos = inc.find_last_of("/");
        return pos == std::string::npos ? inc : inc.substr(pos + 1);
    }
    return {};
}

void DependencyScanner::scan_file(const std::string& file_path, DependencyGraph& graph) {
    std::ifstream file(file_path);
    if (!file) return;
    std::string filename = fs::path(file_path).filename().string();
    std::string line;
    while (std::getline(file, line)) {
        std::string dep = extract_include(line);
        if (!dep.empty()) {
            graph[filename].insert(dep);
        }
    }
}

void DependencyScanner::scan_directory(const std::string& dir_path, DependencyGraph& graph) {
    for (const auto& entry : fs::recursive_directory_iterator(dir_path)) {
        if (entry.is_regular_file() && is_cpp_file(entry.path().string())) {
            scan_file(entry.path().string(), graph);
        }
    }
}

DependencyScanner::DependencyGraph DependencyScanner::scan(const std::string& root_dir) {
    DependencyGraph graph;
    scan_directory(root_dir, graph);
    return graph;
}
