#ifndef OOP_MOVABLE_H
#define OOP_MOVABLE_H
#include "Visible.h"

class Movable : public Visible {
public:
    Movable() {}
    virtual ~Movable() {}
    void move(int x, int y) { _x=x; _y=y; }
    int get_x() const { return _x; }
    int get_y() const { return _y; }

protected:
    int _x;
    int _y;
};

#endif //OOP_MOVABLE_H