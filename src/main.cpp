
#include <iostream>
#include <filesystem>
#include "scanner.hpp"
#include "parser.hpp"
#include "dotgen.hpp"
#include "graphviz.hpp"

int main(int argc, char* argv[]) {
    std::filesystem::path root = argc > 1 ? argv[1] : std::filesystem::current_path();
    auto files = find_source_files(root);
    auto deps = build_dependency_map(files);
    std::string dot_path = "dependencies.dot";
    std::string png_path = "dependencies.png";
    write_dot(deps, dot_path);
    if (render_dot(dot_path, png_path)) {
        std::cout << "Dependency graph generated: " << png_path << std::endl;
        open_image(png_path);
    } else {
        std::cerr << "Failed to render dependency graph. Is Graphviz installed?" << std::endl;
        return 1;
    }
    return 0;
}
