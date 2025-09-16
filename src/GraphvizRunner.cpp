#include "GraphvizRunner.hpp"
#include <cstdlib>
#include <string>

bool GraphvizRunner::render_dot(const std::string& dot_file, const std::string& png_file) {
    std::string cmd = "dot -Tpng '" + dot_file + "' -o '" + png_file + "'";
    int ret = std::system(cmd.c_str());
    return ret == 0;
}
