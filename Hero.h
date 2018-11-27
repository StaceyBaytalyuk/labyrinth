#ifndef OOP_HERO_H
#define OOP_HERO_H

#include "Movable.h"

class Hero : public Movable {
public:
    Hero(int cellSize=30, int statusSize=60, int x=1, int y=10);
    ~Hero();
    void move(int x, int y);
    int get_x() { return _x; }
    int get_y() { return _y; }
    void show();

private:
    int _cellSize;
    int _statusSize;
    int _x;
    int _y;
};

#endif //OOP_HERO_H