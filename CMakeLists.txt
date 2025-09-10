cmake_minimum_required(VERSION 3.20)
project(DependencyVisualizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


include_directories(include)
add_executable(DependencyVisualizer
    src/main.cpp
    src/scanner.cpp
    src/parser.cpp
    src/dotgen.cpp
    src/graphviz.cpp
)

# For std::filesystem on GCC < 9, may need -lstdc++fs
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.0)
        target_link_libraries(DependencyVisualizer stdc++fs)
    endif()
endif()
