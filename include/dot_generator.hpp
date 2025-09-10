#pragma once
#include "dependency_scanner.hpp"
#include <string>
void generate_dot(const std::string& dot_path, const DependencyMap& deps);
