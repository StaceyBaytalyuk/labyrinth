#ifndef OOP_HERO_H
#define OOP_HERO_H

class Hero {
public:
    Hero(int x=1, int y=3);
    ~Hero();
    void move(int x, int y);
    int get_x() { return _x; }
    int get_y() { return _y; }

private:
    int _x;
    int _y;
};

#endif //OOP_HERO_H
