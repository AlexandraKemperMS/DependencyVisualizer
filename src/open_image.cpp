#include "open_image.hpp"
#include <cstdlib>
#include <string>

void ImageOpener::open(const std::string& path) {
#ifdef _WIN32
    std::string cmd = "start \"\" \"" + path + "\"";
#elif __APPLE__
    std::string cmd = "open \"" + path + "\"";
#else
    std::string cmd = "xdg-open \"" + path + "\"";
#endif
    std::system(cmd.c_str());
}
