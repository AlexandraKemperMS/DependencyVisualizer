cmake_minimum_required(VERSION 3.20)
project(DependencyVisualizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DependencyVisualizer
    src/main.cpp
    src/DependencyScanner.cpp
    src/DependencyScanner.hpp
    src/DotGenerator.cpp
    src/DotGenerator.hpp
    src/GraphvizRunner.cpp
    src/GraphvizRunner.hpp
    src/PlatformOpener.cpp
    src/PlatformOpener.hpp
)

# Find Graphviz (for dot)
find_program(GRAPHVIZ_DOT_EXECUTABLE dot)
if(NOT GRAPHVIZ_DOT_EXECUTABLE)
    message(FATAL_ERROR "Graphviz 'dot' not found. Please install Graphviz.")
endif()

install(TARGETS DependencyVisualizer RUNTIME DESTINATION bin)
