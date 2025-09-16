#include "DependencyScanner.hpp"
#include "DotGenerator.hpp"
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
    auto graph = DependencyScanner::scan(root);
    std::string dotFile = "dependencies.dot";
    DotGenerator::write_dot(graph, dotFile);
    std::string pngFile = "dependencies.png";
    if (!GraphvizRunner::render_dot(dotFile, pngFile)) {
        std::cerr << "Failed to render PNG with Graphviz.\n";
        return 2;
    }
    PlatformOpener::open_image(pngFile);
    std::cout << "Dependency graph generated: " << pngFile << std::endl;
    return 0;
}
