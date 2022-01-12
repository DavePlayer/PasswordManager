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
    std::cout << "1. Wyświetl hasła";
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
    switch (choice)
    {
    case 1:
        // display passwords
        this->clearTerminal();
        std::cout << "Struktura haseł (passwd jest folderem przechowującym strukturę haseł): \n";
        system("tree passwd");
        this->displayMenu();
        return 0;
    case 3:
        // create password
        {
            // this->clearTerminal();
            // this->path.initPathPicker();

            if (this->crypComp.isKeyLoaded == true)
            {
                std::cout << "\n\nPodaj ścieżkę do hasła ze struktury passwd [np. test/haslo1]: ";
                std::string path;
                std::cin >> path;
                if (path.find(".txt") == std::string::npos)
                {
                    path += ".txt";
                }
                std::filesystem::path filePath(std::filesystem::current_path() / std::filesystem::path("passwd") / std::filesystem::path(path));
                this->clearTerminal();
                std::string encryptedMessage;
                this->FileManager.open(filePath.string(), std::ios::in);
                if (this->FileManager.is_open())
                {
                    std::getline(this->FileManager, encryptedMessage);
                    std::cout << "hasło: " << encryptedMessage << "\n\n";
                }
                else
                {
                    this->clearTerminal();
                    std::cout << "Podana struktura nie istnieje!\n\n";
                }
                this->FileManager.close();
            }
            else
            {
                this->clearTerminal();
                std::cout << "Żaden Klucz nie został załadowany!\n\n";
            }
            this->displayMenu();
        }
        return 0;
    case 5:
        if (this->crypComp.isKeyLoaded == true)
        {
            std::string ans{};
            while (ans != "Nie" && ans != "Tak")
            {
                this->clearTerminal();
                std::cout << "Klucz jest już załadowany. Chcesz go nadpisać? [Tak/Nie]: ";
                std::cin >> ans;
                if (ans == "Nie")
                {
                    this->clearTerminal();
                    std::cout << "Zaprzestano załadowywania nowego klucza.\n\n";
                }
                else if (ans == "Tak")
                {
                    std::string examplePath = "c:\\scieżka\\do\\klucza.txt";
                    std::cout << "\n\nPodaj ścieżkę do klucza ["
                              << examplePath
                              << "]: ";
                    std::string path;
                    std::cin >> path;
                    this->FileManager.open(path, std::ios::in);
                    if (this->FileManager.is_open())
                    {

                        long long int input;
                        std::vector<int> keys;
                        while (this->FileManager >> input)
                        {
                            keys.push_back(input);
                        }
                        this->FileManager.close();
                        this->crypComp.loadKey(keys[0], keys[1], keys[2], keys[3], keys[4], keys[5]);
                        this->clearTerminal();
                        std::cout << "Załadowano nowy klucz!\n\n";
                    }
                    else
                    {
                        this->clearTerminal();
                        std::cout << "Wystąpił błąd podczas otwierania klucza. Nie pomyliłeś ścieżek?\n\n";
                    }
                }
            }
            this->displayMenu();
        }
        else
        {
            std::string examplePath = "c:\\scieżka\\do\\klucza.txt";
            std::cout << "\n\nPodaj ścieżkę do klucza ["
                      << examplePath
                      << "]: ";
            std::string path;
            std::cin >> path;
            this->FileManager.open(path, std::ios::in);
            if (this->FileManager.is_open())
            {

                long long int input;
                std::vector<int> keys;
                while (this->FileManager >> input)
                {
                    keys.push_back(input);
                }
                this->FileManager.close();
                this->crypComp.loadKey(keys[0], keys[1], keys[2], keys[3], keys[4], keys[5]);
                this->clearTerminal();
                std::cout << "Załadowano nowy klucz!\n\n";
            }
            else
            {
                this->clearTerminal();
                std::cout << "Wystąpił błąd podczas otwierania klucza. Nie pomyliłeś ścieżek?\n\n";
            }
            this->displayMenu();
        }
        return 0;
    case 6:
        this->clearTerminal();
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
        this->clearTerminal();
        std::cout << "Do widzenia!" << std::endl;
        return 0;
    default:
        this->clearTerminal();
        std::cout << "Niepoprawna opcja!\n";
        this->displayMenu();
        return 0;
    }
}
void Menu::clearTerminal()
{
    system(this->clearCommand.c_str());
}
