#ifndef MENU
#define MENU
#include "../crypto/crypto.h"
#include <iostream>

class Menu
{
public:
    std::string clearCommand;
    Crypto crypComp;

    Menu(std::string clearCommand);
    void clearTerminal();
    void displayMenu();
    int manageChoice(unsigned int choice);
};

#endif