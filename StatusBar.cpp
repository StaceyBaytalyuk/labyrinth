#include "StatusBar.h"
#include <iostream>
#include <grx20.h>
#include <grxkeys.h>
#include <cstring>
#include <cmath>

using namespace std;

void StatusBar::show() {
    Visible::show();
    GrLine(0, _size+1, GrMaxX(), _size+1, GrBlack());
    GrTextXY(0.2*GrMaxX(), 0.5*_size, "Stars: ", GrBlack(), GrWhite());
    char buff[2];
    sprintf(buff, "%i", _stars);
    GrTextXY(0.35*GrMaxX(), 0.5*_size, buff, GrBlack(), GrWhite());

    GrTextXY(0.6*GrMaxX(), 0.5*_size, "Time: ", GrBlack(), GrWhite());
    sprintf(buff, "%i", _time);
    GrTextXY(0.75*GrMaxX(), 0.5*_size, buff, GrBlack(), GrWhite());

}

void StatusBar::loss() {
    cout << "You lost!" << endl;
    GrTextXY(0.3*GrMaxX(), 0.5*_size, "You lost!", GrBlack(), GrWhite());
}

void StatusBar::win(int time) {
    _time = time;
    int score = _countScore();
    cout << "You win! Score: " << score << endl;
    GrTextXY(0.3*GrMaxX(), 0.5*_size, "You win!", GrBlack(), GrWhite());
    char buff[2];
    sprintf(buff, "%i", score);
    GrTextXY(0.65*GrMaxX(), 0.5*_size, buff, GrBlack(), GrWhite());
}

int StatusBar::_countScore() {
    int timeBonus = 0;
    if ( _time<=15 ) timeBonus = 50;
    else if ( _time>15 && _time<=25 ) timeBonus = 25;
    return 10*_stars + timeBonus;
}

void StatusBar::reset() {
    _stars = 0;
    _time = 0;
}