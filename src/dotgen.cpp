#include "dotgen.hpp"
#include <fstream>

void write_dot(const std::map<std::string, std::set<std::string>>& deps, const std::string& dot_path) {
    std::ofstream out(dot_path);
    out << "digraph dependencies {\n";
    out << "    node [style=filled, fillcolor=grey];\n";
    for (const auto& [file, includes] : deps) {
        for (const auto& inc : includes) {
            out << "    \"" << file << "\" -> \"" << inc << "\";\n";
        }
    }
    out << "}\n";
}
