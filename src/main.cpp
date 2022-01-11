#include <iostream>
#include "menu/menu.h"
#include <string>

int main()
{
    Menu menu("clear", "/o2/haslo1.txt");
    menu.displayMenu();
    return 0;
}