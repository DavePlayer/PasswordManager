#include "path.h"

void Path::initPathPicker()
{
    std::filesystem::path path(std::filesystem::current_path() / std::filesystem::path("passwd"));
    // std::cout << " " << path << "\n";
    for (const auto &p : std::filesystem::directory_iterator(path))
    {
        std::cout << p << "\n\n";
    }
};