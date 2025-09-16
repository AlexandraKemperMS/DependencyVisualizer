#pragma once
#include <string>
#include "DependencyScanner.hpp"

class DotGenerator {
public:
    static void write_dot(const DependencyScanner::Graph& graph, const std::string& filename);
};
