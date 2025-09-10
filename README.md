# DependencyVisualizer

A C++ tool to analyze and visualize file-level dependencies in a C++ codebase.

## Features
- Scans a directory for C++ source/header files
- Parses `#include` relationships
- Generates a DOT file and renders a PNG dependency graph using Graphviz
- Cross-platform, no GUI frameworks

## Build Instructions

1. **Install Graphviz** (ensure `dot` is in your PATH)
2. **Configure and build with CMake**
   ```sh
   cmake --preset mingw-release
   cmake --build --preset mingw-release
   ```
3. **Run the tool**
   ```sh
   ./build/mingw-release/DependencyVisualizer.exe <path-to-scan>
   ```

The output image will open automatically.

## Requirements
- C++20 or newer
- CMake 3.20+
- Graphviz (for `dot`)

## License
MIT
