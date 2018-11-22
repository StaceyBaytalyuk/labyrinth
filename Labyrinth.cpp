#include "Labyrinth.h"
#include <iostream>
using namespace std;

Labyrinth::Labyrinth() {
    cout << "Labyrinth is created!" << endl;
    _game.set_status(&_status); //ассоциация
}

Labyrinth::~Labyrinth() {
    cout << "Labyrinth is destroyed!" << endl;
}

int Labyrinth::run() {
    cout << "Labyrinth is working..." << endl;
    //show all
    _game.run();
    //try again or exit?
    int tryAgain;
    cin >> tryAgain;
    if(tryAgain){
        _status.reset();
        _game.reset();
    }

}