#include "Enemy.h"
#include <iostream>
#include <grx20.h>
using namespace std;

void Enemy::show() {
    Visible::show();
    int x = _x*(_cellSize+1);
    int y = _y*(_cellSize+1)+_statusSize+1;
    GrTextXY(_cellSize*_x+0.45*_cellSize, _cellSize*_y+_statusSize+0.45*_cellSize, "E", GrBlack(), GrWhite());
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