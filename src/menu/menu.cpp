#include "menu.h"

Menu::Menu(std::string clearCommand, std::string examplePath)
{
    this->clearCommand = clearCommand;
    this->examplePath = examplePath;
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
    case 3:
        // create password
        this->clearTerminal();
        this->path.initPathPicker();
        std::cout << "\n\n";
        // this->displayMenu();
        return 0;
    case 6:
        // generate key
        {
            std::cout << "Tworzenie klucza szyfrującego. Chwilę to zajmie\n";
            std::string key = this->crypComp.createKey();
            if (std::filesystem::exists("klucz.txt"))
            {
                std::string ans = "";
                while (ans != "Nie" && ans != "Tak")
                {
                    this->clearTerminal();
                    std::cout << "Klucz już istnieje. Po jego utracie nie będzie można odczytać juś zapisanych haseł. Chcesz go nadpisać? [Tak/Nie]: ";
                    std::cin >> ans;
                    if (ans == "Nie")
                    {
                        this->clearTerminal();
                        std::cout << "Zaprzestano generacji nowego klucza.\n\n";
                    }
                    else
                    {
                        std::cout << "nadpisywanie klucza!\n";
                        this->FileManager.open("klucz.txt", std::ios::out);
                        this->FileManager << key;
                        this->FileManager.close();
                    }
                }
            }
            else
            {
                this->FileManager.open("klucz.txt", std::ios::out);
                this->FileManager << key;
                this->FileManager.close();
                std::cout << "Utworzono plik klucz.txt\n\n";
            }
        }
        this->displayMenu();
        return 0;
    case 7:
        std::cout << "Do widzenia!" << std::endl;
        return 0;
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
