#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <filesystem>
using DependencyMap = std::unordered_map<std::string, std::unordered_set<std::string>>;
DependencyMap scan_dependencies(const std::filesystem::path& root);
