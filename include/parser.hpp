#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>
#include <filesystem>

std::vector<std::string> extract_includes(const std::string& file_content);
std::map<std::string, std::set<std::string>> build_dependency_map(const std::vector<std::filesystem::path>& files);
