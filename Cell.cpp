#include "Cell.h"
#include <iostream>
using namespace std;

Cell::Cell(int val) {
    _currentValue = val;
    _defaultValue = val;
    cout << "Cell is created! Current value: " << _currentValue
    << ", default value: " << _defaultValue << endl;
}

Cell::~Cell() {
    cout << "Cell is destroyed! Current value: " << _currentValue
    << ", default value: " << _defaultValue << endl;
}

void Cell::toDefault() {
    _currentValue = _defaultValue;
    cout << "Default value: " << _defaultValue
    << ", current value: " << _currentValue << endl;
}

void Cell::set_currentValue(int val) {
    _currentValue = val;
    cout << "Default value: " << _defaultValue
    << ", current value: " << _currentValue << endl;
}