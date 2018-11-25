#ifndef OOP_HERO_H
#define OOP_HERO_H

#include "Visible.h"

class Hero : public Visible {
public:
    Hero(int x=1, int y=3, int cellSize=30, int statusSize=60);
    ~Hero();
    void move(int x, int y);
    int get_x() { return _x; }
    int get_y() { return _y; }
    void show();

    void set_cellSize(int cellSize) {
        _cellSize = cellSize;
    }

    void set_statusSize(int statusSize) {
        _statusSize = statusSize;
    }

private:
    int _cellSize;
    int _statusSize;
    int _x;
    int _y;
};

#endif //OOP_HERO_H
