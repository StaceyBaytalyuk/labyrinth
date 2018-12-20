#ifndef OOP_GAMEFIELD_H
#define OOP_GAMEFIELD_H

#include "StatusBar.h"
#include "Cell.h"
#include "Hero.h"
#include "Enemy.h"

class GameField : public Visible {
public:
    GameField(int width, int height, StatusBar *status);
    ~GameField();
    void show();
    void hide();
    int run();
    void reset();
    int get_size() const { return _size; }
    int get_cellSize() const { return _cellSize; }

private:
    int _checkCell(int x, int y);
    void _takeStar(int x, int y);

    StatusBar *_status;
    int _cellSize;
    static const int _size=12;
    static const int _enemy_counter = 3;
    Enemy *_enemy[_enemy_counter];
    Hero _hero;
    Cell _cell[_size][_size] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 3, 0},
            {0, 1, 1,-1, 1, 0, 1, 1, 1,-1, 1, 0},
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
            {0, 1, 1, 1, 1, 0, 2, 0, 1, 1, 1, 0},
            {0, 1, 0,-1, 1, 1, 1, 0,-1, 1, 1, 0},
            {0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 2, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
            {0, 2, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
            {0, 0, 0, 0, 1,-1, 1, 1, 0, 0, 1, 0},
            {0, 1, 1, 1, 1, 0, 1, 1, 2, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
};

#endif //OOP_GAMEFIELD_H