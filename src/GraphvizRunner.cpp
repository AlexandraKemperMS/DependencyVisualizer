#include "GraphvizRunner.hpp"
#include <cstdlib>
#include <string>

bool GraphvizRunner::render_png(const std::string& dot_path, const std::string& png_path) {
    std::string cmd = "dot -Tpng '" + dot_path + "' -o '" + png_path + "'";
    int ret = std::system(cmd.c_str());
    return ret == 0;
}
