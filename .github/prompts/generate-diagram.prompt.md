---
mode: 'agent'
description: 'Generate a visualizer for file level dependencies'
---

Create a C++20 project which contains multiple files using CMake that analyzes a C++ codebase and visualizes file-level dependencies as a directed graph. The tool should scan a directory, parse #include relationships, and generate a DOT file representing the dependency graph. 

Use Graphviz to render the DOT file to a PNG image. After rendering, automatically open the image with the default viewer (cross-platform if possible). Do not use any GUI frameworks like Qt—just C++ standard library and Graphviz. The project must be cross-platform, easy to build/run with CMake, and include a CMakePresets.json file with a MinGW-specific preset. Only use the filename (not full path) in the graph nodes.

Continue iterating until the project builds, runs with the current repo as the input, and produces the correct output image. Generate a to-do list for implementing the project. 