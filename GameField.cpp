#include "GameField.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <grx20.h>
#include <grxkeys.h>
using namespace std;

GameField::GameField(int width, int height, StatusBar *status) :
_status(status), _cellSize(30) {
    _enemy[0] = new EnemyHoriz(1, 1, 1, _size-3);
    _enemy[1] = new EnemyVertic(6, 1, 1, _size-2);
    _enemy[2] = new EnemyVertic(_size-2, _size-2, 2, _size-2);
}

GameField::~GameField() { _status = nullptr; }

int GameField::run() {
    cout << "Your level: " << _level << endl;
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

        // двигаем врагов
        for(int i=0; i<_enemy_counter; i++){
            x = _enemy[i]->get_x();
            y = _enemy[i]->get_y();
            _cell[_level][y][x].toDefault();
            _enemy[i]->move();
            x = _enemy[i]->get_x();
            y = _enemy[i]->get_y();
            _cell[_level][y][x].set_currentValue(-2);
        }

        // проверка конца игры
        x = _hero.get_x();
        y = _hero.get_y();
        if ( res==-1 || _cell[_level][y][x].get_currentValue()==-2 ) {
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

void GameField::next_level() {
    if ( _level == _level_counter-1 ) _level=0;
    else _level++;
}

void GameField::reset() {
    for(int i = 0; i<_size; i++){
        for(int j = 0; j<_size; j++){
            _cell[_level][i][j].toDefault();
        }
    }
    // вернуть персонажей на начальное положение
    _hero.move(1, 10);
    _enemy[0]->Movable::move(1, 1);
    _enemy[2]->Movable::move(_size-2, 2);

    // положение второго врага меняется в зависимости от карты
    if(_level==0) _enemy[1] = new EnemyVertic(6, 1, 1, _size-2);
    else if(_level==1) _enemy[1] = new EnemyVertic(5, 1, 1, _size-5);
    else if(_level==2) _enemy[1] = new EnemyVertic(5, 1, 1, _size-4);
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
            int value = _cell[_level][i][j].get_currentValue();
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

    // показываем персонажей
    _hero.show();
    for(int i=0; i<_enemy_counter; i++){
        _enemy[i]->show();
    }
}

int GameField::_checkCell(int x, int y) {
    int value = _cell[_level][y][x].get_currentValue();
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

void GameField::_takeStar(int x, int y) {
    _status->addStar();
    _cell[_level][y][x].set_defaultValue(1); // убрали звезду с поля
    _cell[_level][y][x].toDefault();
}