
#include <iostream>
#include <filesystem>
#include "scanner.hpp"
#include "dot_writer.hpp"
#include "graphviz_runner.hpp"
#include "open_image.hpp"

int main(int argc, char* argv[]) {
    std::string input_dir = (argc > 1) ? argv[1] : std::filesystem::current_path().string();
    std::string dot_path = "dependencies.dot";
    std::string png_path = "dependencies.png";

    std::cout << "Scanning directory: " << input_dir << std::endl;
    auto deps = DependencyScanner::scan_directory(input_dir);
    std::cout << "Writing DOT file: " << dot_path << std::endl;
    DotWriter::write_dot(dot_path, deps);
    std::cout << "Rendering PNG with Graphviz..." << std::endl;
    if (!GraphvizRunner::render_dot_to_png(dot_path, png_path)) {
        std::cerr << "Failed to run Graphviz (dot). Is it installed and in PATH?" << std::endl;
        return 1;
    }
    std::cout << "Opening image: " << png_path << std::endl;
    ImageOpener::open(png_path);
    return 0;
}
