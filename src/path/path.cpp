#include "path.h"

PathFinder::PathFinder(bool isWindows)
{
    this->isWindows = isWindows;
}

std::filesystem::path PathFinder::validatePath(std::filesystem::path path)
{
    // for (const auto &p : std::filesystem::directory_iterator(path))
    // {
    //     std::cout << p << "\n";
    // }
    // std::cout << path.string() << "\n";
    std::vector<std::string> explodedPath = this->split(path.string(), '/');
    std::filesystem::path currentPath(std::filesystem::current_path());
    std::filesystem::path tempPath("/");
    int i = 0;
    for (std::string folder : explodedPath)
    {
        if (i == (explodedPath.size() - 1) && folder.find(".txt") == std::string::npos)
            folder += ".txt";
        // std::cout << folder << "\n";
        tempPath = std::filesystem::path(tempPath / std::filesystem::path(folder));
        if (
            currentPath.string().find(folder) == std::string::npos &&
            std::filesystem::exists(tempPath) == false &&
            i != (explodedPath.size() - 1))
        {
            std::cout << "Tworzenie folderu: " << tempPath << "\n";
            std::filesystem::create_directory(tempPath);
        }
        if (i == (explodedPath.size() - 1))
        {
            std::cout << "tworzenie pliku: " << tempPath << "\n";
            std::fstream file(tempPath, std::ios::out);
            file << '\0';
            file.close();
        }
        i++;
    }
    return tempPath;
};

std::string replace(std::string s, char c1, char c2)
{
    int l = s.length();

    // loop to traverse in the string
    for (int i = 0; i < l; i++)
    {

        // check for c1 and replace
        if (s[i] == c1)
            s[i] = c2;

        else if (s[i] == c2)
            s[i] = c1;
    }
    return s;
}

std::vector<std::string> PathFinder::split(std::string string, char mark)
{
    if (this->isWindows == true)
    {
        string = replace(string, '\\', '/');
        std::cout << string << "\n";
    }
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
    words.push_back(word);
    return words;
}