#pragma once
#include <map>
#include <set>
#include <string>

void write_dot(const std::map<std::string, std::set<std::string>>& deps, const std::string& dot_path);
