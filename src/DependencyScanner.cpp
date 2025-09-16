#include "DependencyScanner.hpp"
#include <fstream>
#include <regex>
#include <iostream>

namespace fs = std::filesystem;

DependencyScanner::Graph DependencyScanner::scan(const fs::path& root) {
    Graph graph;
    std::regex include_regex(R"(^\s*#include\s*["]([^"]+)["])");
    for (auto& p : fs::recursive_directory_iterator(root)) {
        if (!p.is_regular_file()) continue;
        // Skip any file in a 'build' directory
        bool in_build = false;
        for (const auto& part : p.path()) {
            if (part == "build") {
                in_build = true;
                break;
            }
        }
        if (in_build) continue;
        auto ext = p.path().extension().string();
        if (ext != ".cpp" && ext != ".hpp" && ext != ".h" && ext != ".cc") continue;
        std::ifstream file(p.path());
        if (!file) continue;
        std::string line;
        std::string filename = p.path().filename().string();
        while (std::getline(file, line)) {
            std::smatch match;
            if (std::regex_search(line, match, include_regex)) {
                std::string dep = match[1];
                graph[filename].insert(dep);
            }
        }
        // Ensure node exists even if no outgoing edges
        if (!graph.count(filename)) graph[filename] = {};
    }
    return graph;
}
