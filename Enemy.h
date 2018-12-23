#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H

#include "Movable.h"

class Enemy : public Movable {
public:
    Enemy() {}
    virtual ~Enemy() {}
    void show();
    virtual void move()=0;

protected:
    bool _direction;
    int _begin;
    int _end;
    int _cellSize=30;
    int _statusSize=60;
};

class EnemyHoriz : public Enemy {
public:
    EnemyHoriz(int x, int y, int beg, int end);
    ~EnemyHoriz() {}
    void move();
};

class EnemyVertic : public Enemy {
public:
    EnemyVertic(int x, int y, int beg, int end);
    ~EnemyVertic() {}
    void move();
};

#endif //OOP_ENEMY_H