#include "scanner.hpp"
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

std::vector<fs::path> find_source_files(const fs::path& root) {
    std::vector<fs::path> files;
    for (auto& p : fs::recursive_directory_iterator(root)) {
        if (p.is_regular_file()) {
            auto ext = p.path().extension().string();
            if (ext == ".cpp" || ext == ".hpp" || ext == ".h" || ext == ".cxx" || ext == ".cc") {
                files.push_back(p.path());
            }
        }
    }
    return files;
}
