#ifndef OOP_STATUSBAR_H
#define OOP_STATUSBAR_H

class StatusBar {
public:
    StatusBar();
    ~StatusBar();
    void addStar();
    void win(int time);
    void loss();
    void reset();

private:
    int _countScore();

    int _time;
    int _stars;
};

#endif //OOP_STATUSBAR_H
