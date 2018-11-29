#include "Labyrinth.h"
#include <iostream>
#include <grx20.h>
#include <grxkeys.h>
using namespace std;

int Labyrinth::run() {
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