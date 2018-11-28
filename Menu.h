#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include <fstream>
namespace quizomat{
class Menu
{
public:
    Menu();

    void show();
    unsigned short getChoice(unsigned short=0);
    void howTo();
    void about();
};
}
#endif // MENU_H
