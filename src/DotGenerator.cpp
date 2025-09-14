#include "DotGenerator.hpp"
#include <fstream>

void DotGenerator::write_dot(const DependencyGraph& graph, const std::string& out_path) {
    std::ofstream out(out_path);
    out << "digraph dependencies {\n";
    for (const auto& [file, deps] : graph) {
        for (const auto& dep : deps) {
            out << "    \"" << file << "\" -> \"" << dep << "\";\n";
        }
        if (deps.empty()) {
            out << "    \"" << file << "\";\n";
        }
    }
    out << "}\n";
}
