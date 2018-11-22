#ifndef OOP_LABYRINTH_H
#define OOP_LABYRINTH_H

#include "GameField.h"

class Labyrinth {
public:
    Labyrinth();
    ~Labyrinth();
    int run();

private:
    GameField _game;
    StatusBar _status;
};

#endif //OOP_LABYRINTH_H
