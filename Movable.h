#ifndef OOP_MOVABLE_H
#define OOP_MOVABLE_H

#include "Visible.h"

class Movable : public Visible {
public:
    Movable() {std::cout << "Movable created!"<<std::endl;}
    virtual ~Movable() {std::cout << "Movable deleted!"<<std::endl;}
    void move(int x, int y) { _x=x; _y=y; }

protected:
    int _x;
    int _y;
};

#endif //OOP_MOVABLE_H