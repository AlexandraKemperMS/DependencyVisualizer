#include "DependencyScanner.hpp"
#include "DotGenerator.hpp"
#include "GraphvizRunner.hpp"
#include "PlatformOpener.hpp"
#include <iostream>
#include <filesystem>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <directory>\n";
        return 1;
    }
    std::filesystem::path root_dir = argv[1];
    auto dependencies = DependencyScanner::scan_directory(root_dir);
    std::string dot_file = "dependencies.dot";
    DotGenerator::write_dot(dot_file, dependencies);
    std::string png_file = "dependencies.png";
    if (!GraphvizRunner::render_dot(dot_file, png_file)) {
        std::cerr << "Failed to render PNG with Graphviz.\n";
        return 2;
    }
    PlatformOpener::open_image(png_file);
    std::cout << "Dependency graph generated: " << png_file << std::endl;
    return 0;
}
