#ifndef OOP_GAMEFIELD_H
#define OOP_GAMEFIELD_H

#include "StatusBar.h"
#include "Cell.h"
#include "Hero.h"
#include "Enemy.h"

class GameField : public Visible {
public:
    GameField(StatusBar *status);
    ~GameField();
    void show();
    void hide();
    int run();
    //void set_status(StatusBar *status) { _status = status; _hero.set_statusSize(_status->get_size()); }
    void reset();
    int get_size() const { return _size; }
    int get_cellSize() const { return _cellSize; }

private:
    int _checkCell(int x, int y);
    void _takeStar(int x, int y);

    StatusBar *_status;
    int _size;
    int _cellSize;
    Cell _cell[12][12] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 3, 0},
            {0, 1, 1, -1, 1, 0, 1, 1, 1,-1, 1, 0},
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
            {0, 1, 1, 1, 1, 0, 2, 0, 1, 1, 1, 0},
            {0, 1, 0,-1, 1, 1, 1, 0, -1, 1, 1, 0},
            {0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 2, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
            {0, 2, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
            {0, 0, 0, 0, 1, -1, 1, 1, 0, 0, 1, 0},
            {0, 1, 1, 1, 1, 0, 1, 1, 2, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Hero _hero;
    //Enemy *_enemy;
    EnemyHoriz _e1, _e2;
    EnemyVertic _e3;
};

#endif //OOP_GAMEFIELD_H