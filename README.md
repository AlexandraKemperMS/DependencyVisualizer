# DependencyVisualizer

A cross-platform C++20 tool to analyze and visualize file-level dependencies in a C++ codebase.

## Features
- Scans a directory for C++ source/header files
- Parses `#include` relationships (filenames only)
- Generates a DOT file and renders a PNG dependency graph using Graphviz
- Opens the output image automatically (Windows, macOS, Linux)
- No GUI dependencies; only C++ standard library and Graphviz required

## Build Instructions

### Prerequisites
- CMake >= 3.20
- C++20 compiler (GCC, Clang, MSVC)
- [Graphviz](https://graphviz.org/download/) (`dot` command must be in PATH)

### Build (example for MinGW on Windows)
```sh
cmake --preset mingw-release
cmake --build --preset mingw-release
```

### Run
```sh
# Analyze current directory
./build/mingw-release/DependencyVisualizer.exe

# Or specify a directory
./build/mingw-release/DependencyVisualizer.exe path/to/your/project
```

The tool will generate `dependencies.dot` and `dependencies.png` in the working directory, and open the PNG automatically.

## License
MIT
