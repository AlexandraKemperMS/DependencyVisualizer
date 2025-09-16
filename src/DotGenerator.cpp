#include "DotGenerator.hpp"
#include <fstream>

void DotGenerator::write_dot(const std::string& filename, const std::map<std::string, std::set<std::string>>& deps) {
    std::ofstream out(filename);
    out << "digraph dependencies {\n";
    out << "  node [color=blue, fontcolor=blue];\n";
    for (const auto& [file, targets] : deps) {
        for (const auto& dep : targets) {
            out << "  \"" << file << "\" -> \"" << dep << "\";\n";
        }
    }
    out << "}\n";
}
