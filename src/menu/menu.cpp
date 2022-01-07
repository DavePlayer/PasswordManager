#include <iostream>
#include "menu.h"

void Menu::displayMenu()
{
    unsigned int option{};
    std::cout << "Menu: " << std::endl;
    std::cout << "\n1. Wyświetl hasła";
    std::cout << "\n2. Stwórz nowe hasło";
    std::cout << "\n3. Odczytaj Hasło";
    std::cout << "\n4. Wygeneruj bezpieczne Hasło";
    std::cout << "\n5. Załaduj klucz szyfrujący";
    std::cout << "\n6. Zakończ program";
    std::cout << "\n\nOpcja[1-5]: ";
    std::cin >> option;
    this->manageChoice(option);
}

int Menu::manageChoice(int choice)
{
    switch (choice)
    {
    case 1:
        // display passwords
        this->clearTerminal();
        std::cout << "Struktura haseł (passwd jest folderem przechowującym strukturę haseł): \n";
        system("tree passwd");
        this->displayMenu();
        break;
    case 6:
        this->clearTerminal();
        std::cout << "Do widzenia!" << std::endl;
        return 1;
        break;
    default:
        this->clearTerminal();
        std::cout << "Niepoprawna opcja!\n";
        this->displayMenu();
    }
}
void Menu::clearTerminal(std::string command)
{
    system(command.c_str());
}
