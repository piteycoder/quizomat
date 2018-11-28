#include "Menu.h"
namespace quizomat{
Menu::Menu(){}

void Menu::show()
{
    system("cls");
    std::cout << "=|=|=|=|= QUIZOMAT ver. 1.0 =|=|=|=|=\t(27.11.2018)\tAutor: Patryk Holub" << std::endl;
    std::cout << "1 - Plany rozwoju\n2 - Jak korzystac\n3 - Start\n0 - Koniec" << std::endl;
}

unsigned short Menu::getChoice(unsigned short ch)
{
    (std::cin >> ch).get();
    system("cls");
    return ch;
}

void Menu::about()
{
    std::cout << "Planowane aktualizacje:" << std::endl;
    std::cout << "Wersja 1.1 - wyswietlanie listy dostepnych testow, znajdujacych sie w osobnym folderze" << std::endl;
    std::cout << "Wersja 1.2 - obsluga polskich znakow" << std::endl;
    std::cout << "Wersja 2.0 - ladna oprawa graficzna i klikanie odpowiedzi zamiast wpisywania" << std::endl;
    std::cout << "ENTER aby wrocic do menu" << std::endl;
    std::cin.get();
    system("cls");
}

void Menu::howTo()
{
    std::cout << "Aby poprawnie korzystac z programu, upewnij sie, ze\n";
    std::cout << "w folderze z plikiem .exe znajduje sie plik .txt z ponumerowanymi pytaniami\n" << std::endl;

    std::cout << "Pytanie musi konczyc sie znakiem \'?\' lub \':\'" << std::endl;
    std::cout << "Odpowiedzi musza znajdowac sie w jednej linii, ostatnia odpowiedz musi byc poprawna." << std::endl;

    std::cout << "Przyklad dobrze sformulowanego pytania i odpowiedzi do nich:\n" << std::endl;
    std::cout << "1. Ile wynosi pierwiastek z 9?" << std::endl;
    std::cout << "4 5 3 2 3" << std::endl;
    std::cout << "        ^ program bedzie porownywal te odpowiedz z wybrana przez uzytkownika.\n" << std::endl;
    std::cout << "Nie uzywaj polskich znakow - pracuje nad tym :)\n" << std::endl;

    std::cout << "Jezeli pomimo tego nadal masz problemy z programem, napisz na: patrykholub@gmail.com" << std::endl;
    std::cout << "\n\nENTER aby wrocic do menu";
    std::cin.get();
    system("cls");
}
}
