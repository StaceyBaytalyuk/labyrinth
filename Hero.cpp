#include "Hero.h"
#include <iostream>
#include <grx20.h>
using namespace std;

Hero::Hero(int cellSize, int statusSize, int x, int y) :
_x(x), _y(y),  _cellSize(cellSize), _statusSize(statusSize)
{ cout << "Hero is created! (" << _x << ", " << _y << ")" << endl; }

Hero::~Hero() { cout << "Hero is destroyed!" << endl; }

void Hero::move(int x, int y) {
    _x = x;
    _y = y;
    cout << "Hero move!"<<endl;
}

void Hero::show() {
    Visible::show();
    int x = _x*(_cellSize+1);
    int y = _y*(_cellSize+1)+_statusSize+1;
    GrTextXY(_cellSize*_x+0.45*_cellSize, _cellSize*_y+_statusSize+0.45*_cellSize, "H", GrBlack(), GrWhite());
    //GrLine(x, y, x+_cellSize, y+_cellSize, GrBlack());
}