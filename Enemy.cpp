#include "Enemy.h"
#include <iostream>
#include <grx20.h>
using namespace std;

void Enemy::show() {
    Visible::show();
    GrTextXY(_cellSize*_x+0.25*_cellSize+_x, _cellSize*_y+_statusSize+0.25*_cellSize+_y, ":V", GrBlack(), GrAllocColor(256, 0, 0));
}

EnemyHoriz::EnemyHoriz(int x, int y, int beg, int end) {
    _x = x;
    _y = y;
    _begin = beg;
    _end = end;
    _direction = true;
}

EnemyVertic::EnemyVertic(int x, int y, int beg, int end) {
    _x = x;
    _y = y;
    _begin = beg;
    _end = end;
    _direction = true;
}

void EnemyHoriz::move() {
    if ( _x == _begin ) _direction = true;
    else if ( _x == _end ) _direction = false;

    if (_direction) {
        _x++;
        Enemy::move(_x, get_y());
    }
    else {
        _x--;
        Enemy::move(_x, get_y());
    }
}

void EnemyVertic::move() {
    if ( _y == _begin ) _direction = true;
    else if ( _y == _end ) _direction = false;

    if (_direction) {
        _y--;
        Enemy::move(get_x(), _y);
    }
    else {
        _y++;
        Enemy::move(get_x(), _y);
    }
}