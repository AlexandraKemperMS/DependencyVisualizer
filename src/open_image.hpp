#pragma once
#include <string>

class ImageOpener {
public:
    // Opens an image file with the default viewer (cross-platform)
    static void open(const std::string& path);
};
