#include "dot_generator.hpp"
#include <fstream>
#include <string>
#include <unordered_set>
#include <iostream>

void generate_dot(const std::string& dot_path, const DependencyMap& deps) {
    // Always overwrite the DOT file
    std::ofstream dot(dot_path, std::ios::trunc);
    if (!dot) {
        std::cerr << "[generate_dot] Failed to open " << dot_path << " for writing!\n";
        return;
    }
    std::cout << "[generate_dot] Writing DOT file: " << dot_path << " (absolute: " << std::filesystem::absolute(dot_path) << ")\n";
    dot << "digraph dependencies {\n";
    dot << "  node [shape=box, style=filled, fillcolor=white];\n";
    std::unordered_set<std::string> all_nodes;
    for (const auto& [file, includes] : deps) {
        all_nodes.insert(file);
        for (const auto& inc : includes) {
            all_nodes.insert(inc);
            dot << "  \"" << file << "\" -> \"" << inc << "\";\n";
        }
    }
    for (const auto& node : all_nodes) {
        dot << "  \"" << node << "\";\n";
    }
    dot << "}\n";
    std::cout << "[generate_dot] DOT file written.\n";
}
