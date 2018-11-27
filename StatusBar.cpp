#include "StatusBar.h"
#include <iostream>
#include <grx20.h>
#include <grxkeys.h>
#include <cstring>

using namespace std;

StatusBar::StatusBar() :
_time(0), _stars(0), _size(60)
{ cout << "StatusBar is created!" << endl; }

StatusBar::~StatusBar() {
    cout << "StatusBar is destroyed!" << endl;
}

void StatusBar::show() {
    Visible::show();
    GrLine(0, _size+1, GrMaxX(), _size+1, GrBlack());
    GrTextXY(0.3*GrMaxX(), 0.5*_size, "Stars: ", GrBlack(), GrWhite());
    switch (_stars) {
        case 0: {
            GrTextXY(0.65*GrMaxX(), 0.5*_size, "0", GrBlack(), GrWhite());
            break;
        }
        case 1: {
            GrTextXY(0.65*GrMaxX(), 0.5*_size, "1", GrBlack(), GrWhite());
            break;
        }
        case 2: {
            GrTextXY(0.65*GrMaxX(), 0.5*_size, "2", GrBlack(), GrWhite());
            break;
        }
        case 3: {
            GrTextXY(0.65*GrMaxX(), 0.5*_size, "3", GrBlack(), GrWhite());
            break;
        }
        case 4: {
            GrTextXY(0.65*GrMaxX(), 0.5*_size, "4", GrBlack(), GrWhite());
            break;
        }
        case 5: {
            GrTextXY(0.65*GrMaxX(), 0.5*_size, "5", GrBlack(), GrWhite());
            break;
        }
    }
}

void StatusBar::addStar() {
    _stars++;
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
    //TODO отображение кол-ва очков
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