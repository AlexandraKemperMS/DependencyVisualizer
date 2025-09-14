
#include "DependencyScanner.hpp"
#include "DotGenerator.hpp"
#include "GraphvizRunner.hpp"
#include "OpenImage.hpp"
#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <source_dir> [output.dot]\n";
        return 1;
    }
    std::string source_dir = argv[1];
    std::string dot_file = argc > 2 ? argv[2] : "dependencies.dot";
    std::string png_file = "dependencies.png";

    DependencyScanner scanner;
    auto graph = scanner.scan(source_dir);
    DotGenerator::write_dot(graph, dot_file);
    std::cout << "DOT file written to: " << dot_file << "\n";

    if (GraphvizRunner::render_png(dot_file, png_file)) {
        std::cout << "PNG image written to: " << png_file << "\n";
        OpenImage::open(png_file);
    } else {
        std::cerr << "Failed to render PNG with Graphviz. Is 'dot' installed?\n";
        return 2;
    }
    return 0;
}
