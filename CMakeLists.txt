cmake_minimum_required(VERSION 3.20)
project(DependencyVisualizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(DependencyVisualizer
    src/main.cpp
    src/dependency_scanner.cpp
    src/dot_generator.cpp
    src/graphviz_runner.cpp
    src/image_opener.cpp
)

target_include_directories(DependencyVisualizer PRIVATE include)

# Find Graphviz (for dot)
find_program(GRAPHVIZ_DOT_EXECUTABLE dot)
if(NOT GRAPHVIZ_DOT_EXECUTABLE)
    message(FATAL_ERROR "Graphviz 'dot' not found. Please install Graphviz and ensure 'dot' is in your PATH.")
endif()

configure_file(${CMAKE_SOURCE_DIR}/include/config.hpp.in ${CMAKE_BINARY_DIR}/config.hpp)

target_compile_features(DependencyVisualizer PRIVATE cxx_std_23)
