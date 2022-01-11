#include "menu.h"

Menu::Menu(std::string clearCommand)
{
    this->clearCommand = clearCommand;
}

void Menu::displayMenu()
{
    unsigned int option{};
    std::cout << "Menu: " << std::endl;
    std::cout << "\n1. Wyświetl hasła";
    std::cout << "\n2. Stwórz nowe hasło";
    std::cout << "\n3. Odczytaj Hasło";
    std::cout << "\n4. Wygeneruj bezpieczne Hasło";
    std::cout << "\n5. Załaduj klucz szyfrujący";
    std::cout << "\n6. Stwórz klucz szyfrujący";
    std::cout << "\n7. Zakończ program";
    std::cout << "\n\nOpcja[1-7]: ";
    std::cin >> option;
    this->manageChoice(option);
}

int Menu::manageChoice(unsigned int choice)
{
    this->clearTerminal();
    switch (choice)
    {
    case 1:
        // display passwords
        std::cout << "Struktura haseł (passwd jest folderem przechowującym strukturę haseł): \n";
        system("tree passwd");
        this->displayMenu();
        return 0;
        break;
    case 6:
        // generate key
        {
            std::cout << "Tworzenie klucza szyfrującego. Chwilę to zajmie\n";
            std::string key = this->crypComp.createKey();
        }
        this->displayMenu();
        return 0;
        break;
    case 7:
        std::cout << "Do widzenia!" << std::endl;
        return 0;
        break;
    default:
        std::cout << "Niepoprawna opcja!\n";
        this->displayMenu();
        return 0;
    }
}
void Menu::clearTerminal()
{
    system(this->clearCommand.c_str());
}
