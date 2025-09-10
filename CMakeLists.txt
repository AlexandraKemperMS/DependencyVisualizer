cmake_minimum_required(VERSION 3.20)
project(DependencyVisualizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(DependencyVisualizer
    src/main.cpp
    src/scanner.cpp
    src/dot_writer.cpp
    src/graphviz_runner.cpp
    src/open_image.cpp
)

# For cross-platform process execution
if (WIN32)
    # Windows-specific settings if needed
else()
    find_package(Threads REQUIRED)
    target_link_libraries(DependencyVisualizer PRIVATE Threads::Threads)
endif()
