#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H

#include "Movable.h"

class Enemy : Movable {
public:
    Enemy() {}
    virtual ~Enemy() {}
    void move(int x, int y) { _x = x; _y = y; }
    void show();
    int get_x() const { return _x; }
    int get_y() const { return _y; }

protected:
    int _x;
    int _y;
    bool _direction;
    int _begin;
    int _end;
    int _cellSize=30;
    int _statusSize=60;
};

class EnemyHoriz : virtual public Enemy {
public:
    EnemyHoriz(int x, int y, int beg, int end);
    ~EnemyHoriz() {}
    void move();
};

class EnemyVertic : virtual public Enemy {
public:
    EnemyVertic(int x, int y, int beg, int end);
    ~EnemyVertic() {};
    void move();
};

#endif //OOP_ENEMY_H