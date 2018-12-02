/* Quizomat to program na podstawie dw�ch odr�bnych plik�w Pytania/Odpowiedzi tworzy quiz.
Wersja 1.0 konsolowa
Wersja 1.1 listowanie wszystkich quizow w folderze
Wersja 2.0 QtCreator
Wersja 3.0 po��czenie z sieci� i baza quiz�w*/

/* WYMAGANIA DOT. DOWOLNEGO QUIZU
1 - Pytania maj� by� wybierane losowo - klasa obs�uguj�ca list� pyta�/odpowiedzi
2 - Po oddaniu odpowiedzi na pytanie, jest ono wyrzucane z listy pyta�/odpowiedzi
3 - Program ma zlicza� sum� punkt�w, pokazywa� max mo�liw� ilo�� do zdobycia i stosunek zdobyte/max - klasa gry
b�dzie wszystko zlicza�, sumowa�, itd.
3.1 - Ma by� dozwolona opcja punkt�w ujemnych - nie dawa� unsigned value
4 - Menu g��wne ma mie� opcje: Jak korzysta�, Start, Koniec. - klasa obs�uguj�ca konsol� - DONE
5 - Konsola ma si� resetowa� po ka�dej odpowiedzi*/

#include "Menu.h"
#include "FileManager.h"
#include "TestHandler.h"
#include "Random.h"

using namespace quizomat;

int main()
{
    Menu menu;
    unsigned short ch{0};

    do{
        menu.show();
        ch = menu.getChoice();
        switch(ch)
        {
        case 1: menu.about();
            break;

        case 3:
            {
                FileManager file;
                if(!file.getFilename())
                    break;


                if(!file.fileSearch())
                    break;


                TestHandler test(file.readQuiz());
                test.setAnswers(file.getAnswers());

                if(!test.init()){
                    std::cout << "Blad w funkcji test.init()" << std::endl;
                    break;
                }

                test.showResult();

            }
            break;

        case 2: menu.howTo();
            break;

        case 0:
            break;

        default: {};
        }

    } while(ch);
    std::cout << "\n=== Dzieki za skorzystanie z mojego programu :) ===" << std::endl;
    return 0;
}
