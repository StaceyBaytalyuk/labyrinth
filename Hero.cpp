#include "Hero.h"
#include <iostream>
using namespace std;

Hero::Hero(int x, int y) {
    _x = x;
    _y = y;
    cout << "Hero is created! (" << _x << ", " << _y << ")\n";
}

Hero::~Hero() {
    cout << "Hero is destroyed!" << _x << endl;
}

void Hero::move(int x, int y) {
    _x = x;
    _y = y;
    cout << "Hero move!"<<endl;
}