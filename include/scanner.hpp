#pragma once
#include <vector>
#include <filesystem>

std::vector<std::filesystem::path> find_source_files(const std::filesystem::path& root);
