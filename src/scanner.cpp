#include "scanner.hpp"
#include <filesystem>
#include <fstream>
#include <regex>
#include <set>

namespace fs = std::filesystem;

DependencyScanner::DependencyMap DependencyScanner::scan_directory(const std::string& root_dir) {
    DependencyMap deps;
    std::regex include_regex(R"(^\s*#\s*include\s*[<\"]([^\">]+)[\">])");
    std::set<std::string> files;

    // Collect all .cpp/.hpp files
    for (auto& p : fs::recursive_directory_iterator(root_dir)) {
        if (p.is_regular_file()) {
            auto ext = p.path().extension().string();
            if (ext == ".cpp" || ext == ".hpp" || ext == ".h" || ext == ".cxx" || ext == ".cc") {
                files.insert(p.path().string());
            }
        }
    }

    // Parse includes
    for (const auto& file : files) {
        std::ifstream in(file);
        if (!in) continue;
        std::string line;
        while (std::getline(in, line)) {
            std::smatch m;
            if (std::regex_search(line, m, include_regex)) {
                // Store only the basename for includes
                std::string inc_base = std::filesystem::path(m[1].str()).filename().string();
                deps[file].push_back(inc_base);
            }
        }
    }
    return deps;
}
