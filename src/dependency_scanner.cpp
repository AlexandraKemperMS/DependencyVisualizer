#include "dependency_scanner.hpp"
#include <filesystem>
#include <fstream>
#include <regex>
#include <unordered_map>
#include <unordered_set>

using DependencyMap = std::unordered_map<std::string, std::unordered_set<std::string>>;

namespace fs = std::filesystem;

static std::regex include_regex(R"(^\s*#\s*include\s*["<]([^">]+)[">])");

DependencyMap scan_dependencies(const fs::path& root) {
    DependencyMap deps;
    for (auto& entry : fs::recursive_directory_iterator(root)) {
        if (!entry.is_regular_file()) continue;
        auto ext = entry.path().extension().string();
        if (ext != ".cpp" && ext != ".hpp" && ext != ".h" && ext != ".cxx" && ext != ".hxx") continue;
        std::string filename = entry.path().filename().string();
        std::ifstream file(entry.path());
        std::string line;
        while (std::getline(file, line)) {
            std::smatch match;
            if (std::regex_search(line, match, include_regex)) {
                std::string inc = match[1].str();
                // Only add if it looks like a filename (no angle brackets, no spaces, no colons)
                // Only add if it looks like a C++ header/source file
                std::string lower_inc = inc;
                std::transform(lower_inc.begin(), lower_inc.end(), lower_inc.begin(), ::tolower);
                // Only add if it is a bare filename (no / or \) and has a valid C++ extension
                auto is_valid_cpp_file = [](const std::string& name) {
                    return (name.ends_with(".h") || name.ends_with(".hpp") || name.ends_with(".cpp") || name.ends_with(".cxx") || name.ends_with(".hxx"));
                };
                if (!inc.empty() && inc.find_first_of("/\\") == std::string::npos && is_valid_cpp_file(lower_inc)) {
                    deps[filename].insert(inc);
                }
            }
        }
    }
    return deps;
}
