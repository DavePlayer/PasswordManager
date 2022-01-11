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
    Path path;
    std::fstream FileManager;
    std::string examplePath;

    Menu(std::string clearCommand, std::string examplePath);
    void clearTerminal();
    void displayMenu();
    int manageChoice(unsigned int choice);
};

#endif