#include "GameField.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <grx20.h>
#include <grxkeys.h>
using namespace std;

GameField::GameField(int width, int height, StatusBar *status) :
_status(status), _cellSize(30) {
    _enemy[0] = new EnemyHoriz(1, 1, 1, 9);
    _enemy[1] = new EnemyHoriz(1, 7, 1, 8);
    _enemy[2] = new EnemyVertic(10, 10, 10, 2);
}

GameField::~GameField() { _status = nullptr; }

int GameField::run() {
    int time = clock();
    while (true) {
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

        cout << fixed << setprecision(5);
        _status->set_time((clock() - time) / CLOCKS_PER_SEC);

        for(int i=0; i<_enemy_counter; i++){
            x = _enemy[i]->get_x();
            y = _enemy[i]->get_y();
            _cell[y][x].toDefault();
            _enemy[i]->move();
            x = _enemy[i]->get_x();
            y = _enemy[i]->get_y();
            _cell[y][x].set_currentValue(-2);
        }

        //чтобы не разминулись
        x = _hero.get_x();
        y = _hero.get_y();
        if ( res==-1 || _cell[y][x].get_currentValue()==-2 ) {
            _status->loss();
            cout << fixed << setprecision(5);
            cout << "Runtime: " <<  (clock() - time) / CLOCKS_PER_SEC << endl;
            return 1;
        } else if(res==1) {
            cout << fixed << setprecision(5);
            cout << "Runtime: " <<  (clock() - time) / CLOCKS_PER_SEC << endl;
            //stop time
            _status->win((clock() - time) / CLOCKS_PER_SEC);
            return 0;
        }
        hide();
        show();
    }
}
/** @return -1 loss, 1 win, 0 continue game*/
int GameField::_checkCell(int x, int y) {
    int value = _cell[y][x].get_currentValue();
    if ( value == -1 || value == -2 )
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
    _hero.move(1, 10);
    _enemy[0]->Movable::move(1, 1);
    _enemy[1]->Movable::move(1, 7);
    _enemy[2]->Movable::move(10, 10);
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
            }
            else if (value==0) {
                GrTextXY(_cellSize*j+j+0.3*_cellSize, _cellSize*i+i+statusSize+0.35*_cellSize, "  ", GrBlack(), GrBlack());
            }
            else if (value==2) {
                GrTextXY(_cellSize*j+j+0.35*_cellSize, _cellSize*i+i+statusSize+0.35*_cellSize, "*", GrBlack(), GrAllocColor(256, 256, 0));
            }
            else if (value==3) {
                GrTextXY(_cellSize*j+j+0.15*_cellSize, _cellSize*i+i+statusSize+0.35*_cellSize, "I^I", GrBlack(), GrAllocColor(0, 256, 0));
            }
        }
    }
    _hero.show();
    for(int i=0; i<_enemy_counter; i++){
        _enemy[i]->show();
    }
}

void GameField::_takeStar(int x, int y) {
    _status->addStar();
    _cell[y][x].set_defaultValue(1);
    _cell[y][x].toDefault();
}