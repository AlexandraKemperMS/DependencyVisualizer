#include "GraphWriter.hpp"
#include <fstream>

void GraphWriter::write_dot(const std::string& filename, const DependencyMap& deps) {
    std::ofstream out(filename);
    out << "digraph dependencies {\n";
    for (const auto& [file, includes] : deps) {
        for (const auto& inc : includes) {
            out << "  \"" << file << "\" -> \"" << inc << "\" [color=blue];\n";
        }
        if (includes.empty()) {
            out << "  \"" << file << "\";\n";
        }
    }
    out << "}\n";
}
