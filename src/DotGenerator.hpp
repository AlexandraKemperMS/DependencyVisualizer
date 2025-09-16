#pragma once
#include <string>
#include <map>
#include <set>

class DotGenerator {
public:
    static void write_dot(const std::string& filename, const std::map<std::string, std::set<std::string>>& deps);
};
