#include <iostream>
#include "menu/menu.h"
#include <string>

#ifdef _WIN32
#define CLEAR "cls"
#define EXAMPLE_PATH "google\\haslo1"
#define EXAMPLE_DIRECTORY "c:\\\\sciezka\\do\\klucza"
#endif
#ifdef __linux__
#define CLEAR "clear"
#define EXAMPLE_PATH "google/haslo1"
#define EXAMPLE_DIRECTORY "/sciezka/do/klucza"
#endif
#ifdef __APPLE__
#define CLEAR "clear"
#define EXAMPLE_PATH "google/haslo1"
#define EXAMPLE_DIRECTORY "/sciezka/do/klucza"
#endif
#ifdef __BSD__
#define CLEAR "clear"
#define EXAMPLE_PATH "google/haslo1"
#define EXAMPLE_DIRECTORY "/sciezka/do/klucza"
#endif

int main()
{
    Menu menu(CLEAR, EXAMPLE_PATH, EXAMPLE_DIRECTORY);
    menu.displayMenu();
    return 0;
}