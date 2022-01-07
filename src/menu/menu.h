#ifndef MENU
#define MENU
#include "../crypto/crypto.h"

class Menu
{
public:
    Crypto crypComp;
    void clearTerminal(std::string = "clear");
    void displayMenu();
    int manageChoice(unsigned int choice);
};

#endif