#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>

class PathFinder
{
public:
    bool isWindows;

    PathFinder(bool isWindows);
    std::filesystem::path validatePath(std::filesystem::path path);
    std::vector<std::string> split(std::string string, char mark);
};