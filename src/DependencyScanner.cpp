#include "DependencyScanner.hpp"
#include <fstream>
#include <regex>

namespace fs = std::filesystem;

DependencyScanner::DependencyMap DependencyScanner::scan_directory(const fs::path& root) {
    DependencyMap deps;
    std::regex include_regex(R"(^\s*#\s*include\s*[<\"]([^\">]+)[\">])");
    
    // Use explicit iterator to allow calling disable_recursion_pending()
    for (auto it = fs::recursive_directory_iterator(root); it != fs::recursive_directory_iterator(); ++it) {
        const auto& p = *it;
        
        // Skip hidden directories and common build directories
        if (p.is_directory()) {
            std::string dirname = p.path().filename().string();
            if (dirname.starts_with('.') || 
                dirname == "build" || 
                dirname == "cmake-build-debug" || 
                dirname == "cmake-build-release") {
                it.disable_recursion_pending();
                continue;
            }
        }
        
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
