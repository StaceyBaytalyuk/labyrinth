#ifndef OOP_HERO_H
#define OOP_HERO_H
#include "Movable.h"

class Hero : public Movable {
public:
    Hero(int cellSize=30, int statusSize=60, int x=1, int y=10);
    ~Hero() {}
    void show();

private:
    int _cellSize;
    int _statusSize;
};

#endif //OOP_HERO_H