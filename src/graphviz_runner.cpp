#include "graphviz_runner.hpp"
#include <cstdlib>
#include <string>

bool run_graphviz(const std::string& dot_path, const std::string& png_path) {
#ifdef _WIN32
    std::string cmd = "dot -Tpng \"" + dot_path + "\" -o \"" + png_path + "\"";
#else
    std::string cmd = "dot -Tpng '" + dot_path + "' -o '" + png_path + "'";
#endif
    return std::system(cmd.c_str()) == 0;
}
