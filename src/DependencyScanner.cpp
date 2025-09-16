#include "DependencyScanner.hpp"
#include <fstream>
#include <regex>

namespace fs = std::filesystem;

DependencyScanner::DependencyMap DependencyScanner::scan_directory(const fs::path& root_dir) {
    DependencyMap deps;
    std::regex include_regex(R"(^\s*#\s*include\s*[<\"]([^\">]+)[\">])");
    for (auto& p : fs::recursive_directory_iterator(root_dir)) {
        if (!p.is_regular_file()) continue;
        auto ext = p.path().extension().string();
        if (ext != ".cpp" && ext != ".hpp" && ext != ".h" && ext != ".cxx" && ext != ".cc") continue;
        std::ifstream file(p.path());
        if (!file) continue;
        std::string line;
        std::string filename = p.path().filename().string();
        while (std::getline(file, line)) {
            std::smatch match;
            if (std::regex_search(line, match, include_regex)) {
                std::string dep = match[1].str();
                deps[filename].insert(dep);
            }
        }
    }
    return deps;
}
