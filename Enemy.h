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
    int _cellSize;
    int _statusSize;
};

class EnemyHoriz : public Enemy {
public:
    EnemyHoriz(int x=1, int y=2, int beg=1, int end=3, int cellSize=30, int statusSize=60);
    ~EnemyHoriz() {}
    void move();
    void show();
};

class EnemyVertic : public Enemy {
public:
    EnemyVertic(int x, int y, int beg, int end, int cellSize=30, int statusSize=60);
    ~EnemyVertic() {};
    void move(int y) { Enemy::move(get_x(), y); }
};

#endif //OOP_ENEMY_H