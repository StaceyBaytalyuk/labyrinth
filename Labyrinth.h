#ifndef OOP_LABYRINTH_H
#define OOP_LABYRINTH_H
#include "GameField.h"

class Labyrinth {
public:
    Labyrinth(int width=10, int hight=10) : _status(), _game(width, hight, &_status) {}
    ~Labyrinth() {}
    int run(); // return 1 if game was interrupted (quit), 0 if normal end

private:
    GameField _game;
    StatusBar _status;
};

#endif //OOP_LABYRINTH_H