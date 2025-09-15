#include "PlatformOpener.hpp"
#include <cstdlib>
#ifdef _WIN32
#  define OPEN_CMD "start "
#elif defined(__APPLE__)
#  define OPEN_CMD "open "
#else
#  define OPEN_CMD "xdg-open "
#endif

void PlatformOpener::open_image(const std::string& filename) {
    std::string cmd = OPEN_CMD;
    cmd += "'" + filename + "'";
    std::system(cmd.c_str());
}
