#include "graphviz_runner.hpp"
#include <cstdlib>
#include <string>

#ifdef _WIN32
constexpr const char* DOT_CMD = "dot.exe";
#else
constexpr const char* DOT_CMD = "dot";
#endif

bool GraphvizRunner::render_dot_to_png(const std::string& dot_path, const std::string& png_path) {
    std::string cmd = std::string(DOT_CMD) + " -Tpng \"" + dot_path + "\" -o \"" + png_path + "\"";
    int ret = std::system(cmd.c_str());
    return ret == 0;
}
