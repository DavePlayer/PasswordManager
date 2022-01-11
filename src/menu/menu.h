#ifndef MENU
#define MENU
#include "../crypto/crypto.h"
#include <iostream>
#include <fstream>
#include <filesystem>

class Menu
{
public:
    std::string clearCommand;
    Crypto crypComp;
    std::fstream FileManager;

    Menu(std::string clearCommand);
    void clearTerminal();
    void displayMenu();
    int manageChoice(unsigned int choice);
};

#endif