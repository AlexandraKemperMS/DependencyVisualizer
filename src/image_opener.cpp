#include "image_opener.hpp"
#include <cstdlib>
#include <string>

bool open_image(const std::string& path) {
#ifdef _WIN32
    std::string cmd = "start \"\" \"" + path + "\"";
#elif __APPLE__
    std::string cmd = "open '" + path + "'";
#else
    std::string cmd = "xdg-open '" + path + "'";
#endif
    return std::system(cmd.c_str()) == 0;
}
