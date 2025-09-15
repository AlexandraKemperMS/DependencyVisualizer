cmake_minimum_required(VERSION 3.20)
project(DependencyVisualizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(DependencyVisualizer
    src/main.cpp
    src/DependencyScanner.cpp
    src/DependencyScanner.hpp
    src/GraphWriter.cpp
    src/GraphWriter.hpp
    src/GraphvizRunner.cpp
    src/GraphvizRunner.hpp
    src/PlatformOpener.cpp
    src/PlatformOpener.hpp
)

# Find Graphviz (for dot)
find_program(GRAPHVIZ_DOT_EXECUTABLE dot)
if(NOT GRAPHVIZ_DOT_EXECUTABLE)
    message(FATAL_ERROR "Graphviz 'dot' executable not found. Please install Graphviz.")
endif()

# Install target
install(TARGETS DependencyVisualizer RUNTIME DESTINATION bin)
