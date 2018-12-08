#include "Hero.h"
#include <iostream>
#include <grx20.h>
using namespace std;

Hero::Hero(int cellSize, int statusSize, int x, int y) :
_x(x), _y(y),  _cellSize(cellSize), _statusSize(statusSize)
{}

void Hero::move(int x, int y) {
    _x = x;
    _y = y;
}

void Hero::show() {
    Visible::show();
    int x = _x*(_cellSize+1);
    int y = _y*(_cellSize+1)+_statusSize+1;
    GrTextXY(_cellSize*_x+0.15*_cellSize+_x, _cellSize*_y+_statusSize+_y+0.35*_cellSize, ":) ", GrBlack(), GrAllocColor(0, 200, 200));
}