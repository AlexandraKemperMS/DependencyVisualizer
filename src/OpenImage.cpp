#include "OpenImage.hpp"
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif

void OpenImage::open(const std::string& path) {
#ifdef _WIN32
    ShellExecuteA(nullptr, "open", path.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
#elif __APPLE__
    std::string cmd = "open '" + path + "'";
    std::system(cmd.c_str());
#else
    std::string cmd = "xdg-open '" + path + "'";
    std::system(cmd.c_str());
#endif
}
