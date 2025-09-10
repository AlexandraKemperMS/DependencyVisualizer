#include "dependency_scanner.hpp"
#include "dot_generator.hpp"
#include "graphviz_runner.hpp"
#include "image_opener.hpp"
#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    namespace fs = std::filesystem;
    std::cout << "[main] Current working directory: " << fs::current_path() << "\n";
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <directory>\n";
        return 1;
    }
    // Always delete the DOT file before generating
    std::string dot_path = "dependencies.dot";
    std::remove(dot_path.c_str());
    fs::path root = argv[1];
    auto dependencies = scan_dependencies(root);
    std::string png_path = "dependencies.png";
    generate_dot(dot_path, dependencies);
    if (!run_graphviz(dot_path, png_path)) {
        std::cerr << "Failed to run Graphviz (dot).\n";
        return 2;
    }
    if (!open_image(png_path)) {
        std::cerr << "Failed to open image.\n";
        return 3;
    }
    std::cout << "Dependency graph generated: " << png_path << "\n";
    return 0;
}
