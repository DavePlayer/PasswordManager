#include "path.h"

void Path::initPathPicker()
{
    std::filesystem::path path(std::filesystem::current_path() / std::filesystem::path("passwd"));
    // std::cout << " " << path << "\n";
    for (const auto &p : std::filesystem::directory_iterator(path))
    {
        std::cout << p << "\n";
    }
};

std::vector<std::string> Path::split(std::string string, char mark)
{
    std::vector<std::string> words;
    std::string word;
    for (auto x : string)
    {
        if (x == mark)
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word += x;
        }
    }
    return words;
}