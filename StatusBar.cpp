#include "StatusBar.h"
#include <iostream>
#include <grx20.h>
#include <grxkeys.h>

using namespace std;

StatusBar::StatusBar() {
    cout << "StatusBar is created!" << endl;
    _time = 0;
    _stars = 0;
    _size = 60;
}

StatusBar::~StatusBar() {
    cout << "StatusBar is destroyed!" << endl;
}

void StatusBar::show() {
    Visible::show();
    GrLine(0, _size+1, GrMaxX(), _size+1, GrBlack());
}

void StatusBar::addStar() {
    _stars++;
}

void StatusBar::loss() {
    cout << "You lost!" << endl;
}

void StatusBar::win(int time) {
    _time = time;
    int score = _countScore();
    cout << "You win! Score: " << score << endl;
}

int StatusBar::_countScore() {
    int timeBonus = 0;
    if ( _time<25 ) timeBonus = 50;
    else if ( _time>=25 && _time<=60 ) timeBonus = 25;
    return 10*_stars + timeBonus;
}

void StatusBar::reset() {
    // 0 stars
}