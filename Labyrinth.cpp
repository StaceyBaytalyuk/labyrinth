#include "Labyrinth.h"
#include <iostream>
#include <grx20.h>
#include <grxkeys.h>
using namespace std;

Labyrinth::Labyrinth() :
_status(), _game(&_status)
{ cout << "Labyrinth is created!" << endl; }

Labyrinth::~Labyrinth() {
    cout << "Labyrinth is destroyed!" << endl;
}

int Labyrinth::run() {
    cout << "Labyrinth is working..." << endl;
    //show all
    int count = _game.get_size();
    int cellSize = _game.get_cellSize();
    int statusSize = _status.get_size();

    GrSetMode(GR_width_height_graphics, count*cellSize + count + 1, count*cellSize + statusSize + count + 2);
    GrClearContext(GrWhite());

    _status.show();
    _game.show();
//TODO обработка попробовать снова или выйти?
    return _game.run();
}