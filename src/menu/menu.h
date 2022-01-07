#ifndef MENU
#define MENU

class Menu
{
public:
    void clearTerminal(std::string = "clear");
    void displayMenu();
    int manageChoice(int choice);
};

#endif