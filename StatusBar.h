#ifndef OOP_STATUSBAR_H
#define OOP_STATUSBAR_H

#include "Visible.h"

class StatusBar : public Visible {
public:
    StatusBar() : _time(0), _stars(0), _size(60) {}
    ~StatusBar() {}
    void show();
    void addStar() { _stars++; }
    void win(int time);
    void loss();
    void reset();
    int get_size() const { return _size; }

private:
    int _countScore();
    int _time;
    int _stars;
    int _size;
};

#endif //OOP_STATUSBAR_H