cmake_minimum_required(VERSION 3.20)
project(DependencyVisualizer 
    LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "A cross-platform C++20 tool to analyze and visualize C++ #include dependencies")

# C++ standard requirements
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler-specific options
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -pedantic)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-g)
        # Enable sanitizers in debug builds if supported
        include(CheckCXXCompilerFlag)
        check_cxx_compiler_flag("-fsanitize=address,undefined" COMPILER_SUPPORTS_SANITIZERS)
        if(COMPILER_SUPPORTS_SANITIZERS)
            add_compile_options(-fsanitize=address,undefined)
            add_link_options(-fsanitize=address,undefined)
        endif()
    endif()
endif()

# Source files
file(GLOB_RECURSE DV_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(dependency-visualizer ${DV_SOURCES})
target_include_directories(dependency-visualizer PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Find Graphviz (for dot)
find_program(GRAPHVIZ_DOT_EXECUTABLE dot)
if(NOT GRAPHVIZ_DOT_EXECUTABLE)
    message(WARNING "Graphviz 'dot' not found. Please install Graphviz. PNG rendering will fail at runtime.")
endif()

# Installation
install(TARGETS dependency-visualizer RUNTIME DESTINATION bin)
