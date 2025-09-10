#include "parser.hpp"
#include <fstream>
#include <regex>
#include <sstream>

std::vector<std::string> extract_includes(const std::string& file_content) {
    std::vector<std::string> includes;
    std::regex include_regex(R"(^\s*#\s*include\s*[<"]([^">]+)[">])");
    std::smatch match;
    std::istringstream iss(file_content);
    std::string line;
    while (std::getline(iss, line)) {
        if (std::regex_search(line, match, include_regex)) {
            auto pos = match[1].str().find_last_of("/\\");
            includes.push_back(pos == std::string::npos ? match[1].str() : match[1].str().substr(pos + 1));
        }
    }
    return includes;
}

std::map<std::string, std::set<std::string>> build_dependency_map(const std::vector<std::filesystem::path>& files) {
    std::map<std::string, std::set<std::string>> deps;
    for (const auto& file : files) {
        std::ifstream in(file);
        if (!in) continue;
        std::string content((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
        auto includes = extract_includes(content);
        deps[file.filename().string()].insert(includes.begin(), includes.end());
    }
    return deps;
}
