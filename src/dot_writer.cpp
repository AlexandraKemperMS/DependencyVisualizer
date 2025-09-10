#include "dot_writer.hpp"
#include <fstream>
#include <string_view>
#include <set>
#include <filesystem>

void DotWriter::write_dot(const std::string& out_path, const std::unordered_map<std::string, std::vector<std::string>>& deps) {
    std::ofstream out(out_path);
    if (!out) return;
    out << "digraph dependencies {\n";

    // Build a set of all known file basenames
    std::set<std::string> known_files;
    for (const auto& [file, _] : deps) {
        known_files.insert(std::filesystem::path(file).filename().string());
    }

    // Draw edges only to known files, use basenames for nodes
    for (const auto& [file, includes] : deps) {
        std::string file_node = std::filesystem::path(file).filename().string();
        for (const auto& inc : includes) {
            if (known_files.count(inc)) {
                out << "  \"" << file_node << "\" -> \"" << inc << "\";\n";
            }
        }
    }
    out << "}\n";
}
