# DependencyVisualizer

A C++20 tool to analyze C++ codebases and visualize file-level dependencies as a directed graph.

## Features
- Scans a directory for C++ source/header files
- Parses `#include` relationships
- Generates a DOT file for the dependency graph
- Uses Graphviz to render a PNG image
- Opens the image with the default viewer (cross-platform)

## Build & Run

### Prerequisites
- CMake 3.20+
- C++20 compiler (GCC, Clang, MSVC, MinGW)
- [Graphviz](https://graphviz.org/) (`dot` must be in your PATH)

### Build (example for MinGW)
```sh
cmake --preset mingw-release
cmake --build --preset mingw-release
```

### Run
```sh
./build/mingw-release/DependencyVisualizer.exe <path-to-scan>
```
If no path is given, scans the current directory.

## Output
- `dependencies.dot`: DOT file
- `dependencies.png`: PNG image (auto-opened)
