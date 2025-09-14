#pragma once
#include <string>

class GraphvizRunner {
public:
    static bool render_png(const std::string& dot_path, const std::string& png_path);
};
