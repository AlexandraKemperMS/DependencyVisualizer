#pragma once
#include <string>

class GraphvizRunner {
public:
    // Runs Graphviz to render a DOT file to PNG
    static bool render_dot_to_png(const std::string& dot_path, const std::string& png_path);
};
