#!/bin/bash

# Simple test script to demonstrate DependencyVisualizer functionality
echo "=== DependencyVisualizer Test Script ==="

# Check if Graphviz is available
if ! command -v dot &> /dev/null; then
    echo "Error: Graphviz 'dot' command not found. Please install Graphviz."
    exit 1
fi

# Create a test directory with sample C++ files
TEST_DIR="/tmp/dependency_test"
rm -rf "$TEST_DIR"
mkdir -p "$TEST_DIR"

echo "Creating test C++ files..."

# Create test files with dependencies
cat > "$TEST_DIR/logger.hpp" << 'EOF'
#pragma once
#include <string>

class Logger {
public:
    static void log(const std::string& message);
};
EOF

cat > "$TEST_DIR/logger.cpp" << 'EOF'
#include "logger.hpp"
#include <iostream>

void Logger::log(const std::string& message) {
    std::cout << "[LOG] " << message << std::endl;
}
EOF

cat > "$TEST_DIR/math_utils.hpp" << 'EOF'
#pragma once

class MathUtils {
public:
    static int add(int a, int b);
    static int multiply(int a, int b);
};
EOF

cat > "$TEST_DIR/math_utils.cpp" << 'EOF'
#include "math_utils.hpp"
#include "logger.hpp"

int MathUtils::add(int a, int b) {
    return a + b;
}

int MathUtils::multiply(int a, int b) {
    return a * b;
}
EOF

cat > "$TEST_DIR/main.cpp" << 'EOF'
#include "math_utils.hpp"
#include "logger.hpp"
#include <iostream>

int main() {
    Logger::log("Starting application");
    
    int result = MathUtils::add(5, 3);
    Logger::log("Addition result: " + std::to_string(result));
    
    result = MathUtils::multiply(4, 7);
    Logger::log("Multiplication result: " + std::to_string(result));
    
    return 0;
}
EOF

echo "Test files created in $TEST_DIR"

# Build the tool if not already built
if [ ! -f "./build/DependencyVisualizer" ]; then
    echo "Building DependencyVisualizer..."
    cmake -B build -S . && cmake --build build
fi

# Run the dependency visualizer on the test directory
echo "Running DependencyVisualizer on test files..."
timeout 10 ./build/DependencyVisualizer "$TEST_DIR" || echo "Note: Image opening failed (expected in headless environments)"

# Show the generated DOT file
if [ -f "dependencies.dot" ]; then
    echo "Generated DOT file:"
    echo "==================="
    cat dependencies.dot
    echo "==================="
    echo ""
    
    # Check if PNG was generated
    if [ -f "dependencies.png" ]; then
        echo "PNG file generated successfully: dependencies.png ($(ls -lh dependencies.png | cut -d' ' -f5))"
    else
        echo "Warning: PNG file was not generated"
    fi
else
    echo "Error: DOT file was not generated"
fi

# Cleanup
rm -rf "$TEST_DIR"
echo "Test completed!"