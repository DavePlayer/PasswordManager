#include <iostream>
#include "menu/menu.h"
#include <string>
#include <filesystem>

#ifdef _WIN32
#define CLEAR "cls"
#define EXAMPLE_PATH "google/haslo1"
#define EXAMPLE_DIRECTORY "c:\\\\sciezka\\do\\klucza"
#define TREE "tree passwd /f > tree.txt"
#define ISWINDOWS true
#endif
#ifdef __linux__
#define CLEAR "clear"
#define EXAMPLE_PATH "google/haslo1"
#define EXAMPLE_DIRECTORY "/sciezka/do/klucza"
#define TREE "tree passwd > tree.txt"
#define ISWINDOWS false
#endif
#ifdef __APPLE__
#define CLEAR "clear"
#define EXAMPLE_PATH "google/haslo1"
#define EXAMPLE_DIRECTORY "/sciezka/do/klucza"
#define TREE "tree passwd"
#define ISWINDOWS false
#endif
#ifdef __BSD__
#define CLEAR "clear"
#define EXAMPLE_PATH "google/haslo1"
#define EXAMPLE_DIRECTORY "/sciezka/do/klucza"
#define TREE "tree passwd"
#define ISWINDOWS false
#endif

int main()
{
    if (std::filesystem::exists(std::filesystem::current_path() / std::filesystem::path("passwd")) == false)
    {
        std::filesystem::create_directory(std::filesystem::current_path() / std::filesystem::path("passwd"));
    }
    Menu menu(CLEAR, EXAMPLE_PATH, EXAMPLE_DIRECTORY, TREE, ISWINDOWS);
    menu.displayMenu();
    return 0;
}