#include "DependencyScanner.hpp"
#include "GraphWriter.hpp"
#include "GraphvizRunner.hpp"
#include "PlatformOpener.hpp"
#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <directory>\n";
        return 1;
    }
    std::filesystem::path root = argv[1];
    auto deps = DependencyScanner::scan_directory(root);
    std::string dot_file = "dependencies.dot";
    GraphWriter::write_dot(dot_file, deps);
    std::string png_file = "dependencies.png";
    if (!GraphvizRunner::run_dot(dot_file, png_file)) {
        std::cerr << "Failed to run Graphviz dot.\n";
        return 2;
    }
    PlatformOpener::open_image(png_file);
    std::cout << "Dependency graph generated: " << png_file << std::endl;
    return 0;
}
