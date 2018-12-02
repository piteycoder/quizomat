/* Quizomat to program na podstawie dwóch odrêbnych plików Pytania/Odpowiedzi tworzy quiz.
Wersja 1.0 konsolowa
Wersja 1.1 listowanie wszystkich quizow w folderze
Wersja 2.0 QtCreator
Wersja 3.0 po³¹czenie z sieci¹ i baza quizów*/

/* WYMAGANIA DOT. DOWOLNEGO QUIZU
1 - Pytania maj¹ byæ wybierane losowo - klasa obs³uguj¹ca listê pytañ/odpowiedzi
2 - Po oddaniu odpowiedzi na pytanie, jest ono wyrzucane z listy pytañ/odpowiedzi
3 - Program ma zliczaæ sumê punktów, pokazywaæ max mo¿liw¹ iloœæ do zdobycia i stosunek zdobyte/max - klasa gry
bêdzie wszystko zliczaæ, sumowaæ, itd.
3.1 - Ma byæ dozwolona opcja punktów ujemnych - nie dawaæ unsigned value
4 - Menu g³ówne ma mieæ opcje: Jak korzystaæ, Start, Koniec. - klasa obs³uguj¹ca konsolê - DONE
5 - Konsola ma siê resetowaæ po ka¿dej odpowiedzi*/

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
