#include "menu.h"

Menu::Menu(std::string clearCommand, std::string examplePath, std::string exampleDirectory, std::string treeCommand, bool isWindows)
{
    this->clearCommand = clearCommand;
    this->examplePath = examplePath;
    this->exampleDirectory = exampleDirectory;
    this->treeCommand = treeCommand;
    this->isWindows = isWindows;
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
        {
            this->clearTerminal();
            std::cout << "Struktura haseł (passwd jest folderem przechowującym strukturę haseł): \n\n";
            system(this->treeCommand.c_str());
            this->FileManager.open("tree.txt");
            std::string line;
            int i = 1;
            while (std::getline(this->FileManager, line))
            {
                if (this->isWindows == true && i < 3)
                {
                    std::cout << line << "\n";
                }
                else if (this->isWindows == false)
                {
                    std::cout << line << "\n";
                }
            }
            std::cout << "\n";
            this->FileManager.close();
            this->displayMenu();
        }
        return 0;
    case 2:
        if (this->crypComp.isKeyLoaded == false)
        {
            this->clearTerminal();
            std::cout << "Nie załadowano żadnego klucza szyfrującego!\n\n";
        }
        else
        {
            std::cout << "\n\nPodaj strukturę hasła [np. " << this->examplePath << "]: ";
            std::string userInput;
            std::cin >> userInput;
            std::filesystem::path path(std::filesystem::current_path() / std::filesystem::path("passwd") / std::filesystem::path(userInput));
            path = this->pathFinder.validatePath(path); // creates unexistent directories and files inside passwd
            std::string password;
            std::cout << "\n\nPodaj swoje hasło: ";
            std::cin >> password;
            this->FileManager.open(path, std::ios::out);
            this->FileManager << this->crypComp.encrypt(password);
            this->FileManager.close();
            this->clearTerminal();
            std::cout << "Stworzono nowe hasło!\n\n";
        }
        this->displayMenu();
        return 0;
    case 3:
        // create password
        {
            // this->clearTerminal();
            // this->path.initPathPicker();

            if (this->crypComp.isKeyLoaded == true)
            {
                std::cout << "\n\nPodaj ścieżkę do hasła ze struktury passwd [np. " << this->examplePath << "]: ";
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
                    encryptedMessage = this->crypComp.decrypt(encryptedMessage);
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
                std::cout << "Nie załadowano żadnego klucza szyfrującego!\n\n";
            }
            this->displayMenu();
        }
        return 0;
    case 4:
    {
        int *length = nullptr;
        do
        {
            if (length != nullptr)
                std::cout << "Hasło musi być dłuższe niż 5 znaków!\n";
            std::cout << "\n\nPodaj długośc hasła: ";
            length = new int;
            std::cin >> *length;
            this->clearTerminal();
        } while (length != nullptr && *length < 6);
        std::cout << "Wygenerowane hasło: " << this->crypComp.generateSafePassword(*length) << "\n\n";
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
                    std::cout << "\n\nPodaj ścieżkę do klucza [np. "
                              << this->exampleDirectory
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
            std::cout << "\n\nPodaj ścieżkę do klucza [np. "
                      << this->exampleDirectory
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
                        this->clearTerminal();
                        std::cout << "nadpisywanie klucza!\n\n";
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
