#ifndef MENU
#define MENU
#include "../crypto/crypto.h"
#include "../path/path.h"
#include <iostream>
#include <fstream>
#include <filesystem>

class Menu
{
public:
    std::string clearCommand;
    Crypto crypComp;
    PathFinder *pathFinder;
    std::fstream FileManager;
    std::string examplePath;
    std::string exampleDirectory;
    std::string treeCommand;
    bool isWindows;

    Menu(std::string clearCommand, std::string examplePath, std::string exampleDirectory, std::string treeCommand, bool isWindows);
    void clearTerminal();
    void displayMenu();
    int manageChoice(unsigned int choice);
};

#endif