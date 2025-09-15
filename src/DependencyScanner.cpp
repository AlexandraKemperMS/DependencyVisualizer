#include "DependencyScanner.hpp"
#include <fstream>
#include <regex>

namespace fs = std::filesystem;

DependencyScanner::DependencyMap DependencyScanner::scan_directory(const fs::path& root) {
    DependencyMap deps;
    std::regex include_regex(R"(^\s*#\s*include\s*[<\"]([^\">]+)[\">])");
    for (auto& p : fs::recursive_directory_iterator(root)) {
        if (!p.is_regular_file()) continue;
        auto ext = p.path().extension().string();
        if (ext != ".cpp" && ext != ".hpp" && ext != ".h" && ext != ".cxx" && ext != ".cc") continue;
        std::string filename = p.path().filename().string();
        std::ifstream file(p.path());
        std::string line;
        while (std::getline(file, line)) {
            std::smatch m;
            if (std::regex_search(line, m, include_regex)) {
                deps[filename].insert(m[1].str());
            }
        }
        if (!deps.contains(filename)) deps[filename] = {};
    }
    return deps;
}
