#include "Labyrinth.h"
#include <iostream>
#include <grx20.h>
using namespace std;

int Labyrinth::run() {
    int count = _game.get_size();
    int cellSize = _game.get_cellSize();
    int statusSize = _status.get_size();
    GrSetMode(GR_width_height_graphics, count*cellSize + count + 1, count*cellSize + statusSize + count + 2);
    while (true) {
        GrClearContext(GrWhite());
        _status.show();
        _game.show();
        int res = _game.run();
        if (res==0) { // win
            _game.next_level();
            _status.reset();
            _game.reset();
        }
        else if ( res==1 ) { // loss
            cout << "Do you want to play again? Enter 0 or 1: ";
            int answer;
            cin >> answer;
            if(answer) {
                _status.reset();
                _game.reset();
            } else return 0;
        }
        else if ( res==2 ) { // restart
            _status.reset();
            _game.reset();
        }
        else if ( res==3 ) return 1; // quit
    }
}