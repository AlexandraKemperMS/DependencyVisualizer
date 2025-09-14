cmake_minimum_required(VERSION 3.20)
project(DependencyVisualizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE DV_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(dependency-visualizer ${DV_SOURCES})
target_include_directories(dependency-visualizer PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Find Graphviz (for dot)
find_program(GRAPHVIZ_DOT_EXECUTABLE dot)
if(NOT GRAPHVIZ_DOT_EXECUTABLE)
    message(WARNING "Graphviz 'dot' not found. Please install Graphviz. PNG rendering will fail at runtime.")
endif()

install(TARGETS dependency-visualizer RUNTIME DESTINATION bin)
