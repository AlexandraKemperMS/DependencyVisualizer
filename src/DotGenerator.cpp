#include "DotGenerator.hpp"
#include <fstream>

void DotGenerator::write_dot(const DependencyScanner::Graph& graph, const std::string& filename) {
    std::ofstream out(filename);
    out << "digraph dependencies {\n";
    out << "  node [color=blue, style=filled, fillcolor=lightblue];\n";
    for (const auto& [file, deps] : graph) {
        for (const auto& dep : deps) {
            out << "  \"" << file << "\" -> \"" << dep << "\";\n";
        }
        if (deps.empty()) {
            out << "  \"" << file << "\";\n";
        }
    }
    out << "}\n";
}
