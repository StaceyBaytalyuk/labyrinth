#ifndef OOP_GAMEFIELD_H
#define OOP_GAMEFIELD_H

#include "StatusBar.h"
#include "Cell.h"
#include "Hero.h"

class GameField {
public:
    GameField();
    ~GameField();
    int run();
    void set_status(StatusBar *status) { _status = status; }
    void reset();
private:
    int _checkCell(int x, int y);
    void _takeStar(int x, int y){}

    StatusBar *_status;
    int _size;
    Cell _cell[5][5] = { //TODO заполнить поле
            {0, 0, 0, 0, 0},
            {0, 1, 1, 3, 0},
            {0, 1, 1, 1, 0},
            {0, 1, -1, 1, 0},
            {0, 0, 0, 0, 0}
    };
    Hero _hero;

};

#endif //OOP_GAMEFIELD_H
