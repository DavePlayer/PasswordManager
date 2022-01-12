#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

class Path
{
public:
    void initPathPicker();
    std::vector<std::string> split(std::string string, char mark);
};