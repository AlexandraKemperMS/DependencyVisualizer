#include "graphviz.hpp"
#include <cstdlib>

bool render_dot(const std::string& dot_path, const std::string& png_path) {
#ifdef _WIN32
    std::string cmd = "dot -Tpng \"" + dot_path + "\" -o \"" + png_path + "\"";
#else
    std::string cmd = "dot -Tpng '" + dot_path + "' -o '" + png_path + "'";
#endif
    return std::system(cmd.c_str()) == 0;
}

void open_image(const std::string& png_path) {
#ifdef _WIN32
    std::string cmd = "start \"\" \"" + png_path + "\"";
#elif __APPLE__
    std::string cmd = "open '" + png_path + "'";
#else
    std::string cmd = "xdg-open '" + png_path + "'";
#endif
    std::system(cmd.c_str());
}
