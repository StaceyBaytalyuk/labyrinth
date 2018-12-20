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
    int run(); // return 0 win, 1 loss, 2 restart, 3 quit
    void next_level();
    void reset();
    int get_size() const { return _size; }
    int get_cellSize() const { return _cellSize; }

private:
    int _checkCell(int x, int y); // return -1 loss, 1 win, 0 continue game
    void _takeStar(int x, int y);

    int _cellSize;
    StatusBar *_status;
    static const int _enemy_counter = 3; // кол-во врагов
    Enemy *_enemy[_enemy_counter];
    Hero _hero;
    static const int _size=12; // кол-во клеток
    int _level=0; // текущий уровень
    static const int _level_counter = 3; // всего уровней

    Cell _cell[_level_counter][_size][_size] = {
        //0 level
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 2, 1, 1, 1, 1, 1, 1, 1, 3, 0},
                {0, 1, 1,-1, 1, 0, 1, 0, 2,-1, 1, 0},
                {0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                {0, 1, 1, 1, 1, 0, 1, 0, 2, 1, 1, 0},
                {0, 1, 0,-1, 1, 1, 1, 0,-1, 0, 1, 0},
                {0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0},
                {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
                {0, 2, 0, 1, 1, 0, 1,-1, 1, 0, 1, 0},
                {0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 2, 0},
                {0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        },

        //1 level
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 1, 1, 1, 1, 1, 1, 2, 1, 3, 0},
                {0,-1, 1, 0, 2, 1, 0, 1, 0, 1, 1, 0},
                {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0},
                {0, 1, 0, 1,-1, 1, 1, 1, 1, 1, 1, 0},
                {0, 2, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0},
                {0, 0, 0, 1, 0, 1, 2, 0, 1, 0, 1, 0},
                {0, 1, 1, 1, 0, 1, 1, 0, 1,-1, 1, 0},
                {0, 1, 1,-1, 0, 0, 0, 0, 2, 1, 1, 0},
                {0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0},
                {0, 1, 1, 1, 1,-1, 1, 1, 1, 1, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        },

        //2 level
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0},
                {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
                {0, 1, 0, 2, 0, 1, 1, 1, 2, 0, 1, 0},
                {0, 1, 1, 1, 0, 1,-1, 1, 0, 0, 1, 0},
                {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
                {0, 1, 1, 1,-1, 1, 1, 0, 2,-1, 1, 0},
                {0, 1,-1, 1, 1, 1, 1, 0, 0, 0, 1, 0},
                {0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 2, 0},
                {0, 1, 0, 0, 0, 0, 0,-1, 1, 0, 1, 0},
                {0, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        }
    };
};

#endif //OOP_GAMEFIELD_H