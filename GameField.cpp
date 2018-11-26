#include "GameField.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <grx20.h>
#include <grxkeys.h>
using namespace std;

GameField::GameField(StatusBar *status) :
_status(status), _size(5), _cellSize(30)
{ cout << "GameField is created!" << endl; }

GameField::~GameField() {
    _status = nullptr;
    cout << "GameField is destroyed!" << endl;
}

int GameField::run() {
    cout << "GameField is working... Association with "  << &_status << endl;
    //start time
    int time = clock();
    while (true) {
        _cell[_enemy.get_y()][_enemy.get_x()].toDefault();
        _enemy.move();
        _cell[_enemy.get_y()][_enemy.get_x()].set_currentValue(-2);
        int x = _hero.get_x();
        int y = _hero.get_y();
        int res = 0;

        switch (GrKeyRead()) {
            case 'w': {
                res = _checkCell(x, y-1);
                break;
            }
            case 'a': {
                res = _checkCell(x-1, y);
                break;
            }
            case 's': {
                res = _checkCell(x, y+1);
                break;
            }
            case 'd': {
                res = _checkCell(x+1, y);
                break;
            }
            case 'r': return 2;
            case 'q': return 3;
        }
        if(res==1) {
            cout << fixed << setprecision(5);
            cout << "Runtime: " <<  (clock() - time) / CLOCKS_PER_SEC << endl;
            //stop time
            _status->win((clock() - time) / CLOCKS_PER_SEC);
            return 0;
        } else if (res==-1) {
            _status->loss();
            cout << fixed << setprecision(5);
            cout << "Runtime: " <<  (clock() - time) / CLOCKS_PER_SEC << endl;
            return 1;
        }
        hide();
        show();
    }
}
/** @return -1 loss, 1 win, 0 continue game*/
int GameField::_checkCell(int x, int y) {
    int value = _cell[y][x].get_currentValue();
    if ( value == -1 || value == -2)
        return -1;
    else if ( value == 1 )
        _hero.move(x, y);
    else if ( value == 2 ) {
        _takeStar(x, y);
        _hero.move(x, y);
    }
    else if ( value == 3 )
        return 1;
    return 0;
}

void GameField::reset() {
    for(int i = 0; i<_size; i++){
        for(int j = 0; j<_size; j++){
            _cell[i][j].toDefault();
        }
    }
    _hero.move(1, 3);//TODO заменить координаты, дописать врагов
}

void GameField::hide() {
    Visible::hide();
    _status->hide();
    _hero.hide();
    GrClearContext(GrWhite());
}

void GameField::show() {
    Visible::show();
    _status->show();
    int statusSize = _status->get_size() + 1;
//рисуем клетки
    for (int i = statusSize+_cellSize+1; i<=GrMaxY(); i+=_cellSize+1)
        GrLine(0, i, GrMaxX(), i, GrBlack());

    for (int i=0; i<=GrMaxX(); i+=_cellSize+1)
        GrLine(i, statusSize, i, GrMaxY(), GrBlack());

//добавляем содержимое клеток
    for (int i=0; i<_size; i++) {
        for (int j=0; j<_size; j++) {
            int value = _cell[i][j].get_currentValue();
            if (value==-1) {
                GrTextXY(_cellSize*j+j+0.35*_cellSize, _cellSize*i+i+statusSize+0.35*_cellSize, "O", GrBlack(), GrWhite());
            } else if (value==-2) {
                GrTextXY(_cellSize*j+j+0.35*_cellSize, _cellSize*i+i+statusSize+0.35*_cellSize, "E", GrBlack(), GrWhite());
            }
            else if (value==0) {
                GrTextXY(_cellSize*j+j+0.35*_cellSize, _cellSize*i+i+statusSize+0.35*_cellSize, "#", GrBlack(), GrWhite());
            }
            else if (value==2) {
                GrTextXY(_cellSize*j+j+0.35*_cellSize, _cellSize*i+i+statusSize+0.35*_cellSize, "S", GrBlack(), GrWhite());
            }
            else if (value==3) {
                GrTextXY(_cellSize*j+j+0.35*_cellSize, _cellSize*i+i+statusSize+0.35*_cellSize, "D", GrBlack(), GrWhite());
            }
        }
    }

    _hero.show();
    _enemy.show();
}

void GameField::_takeStar(int x, int y) {
    _status->addStar();
    _cell[y][x].set_currentValue(1);
}
