#pragma once
#include <string>

class GraphvizRunner {
public:
    static bool render_dot(const std::string& dot_file, const std::string& png_file);
};
