#ifndef OOP_CELL_H
#define OOP_CELL_H

class Cell {
public:
    Cell(int val) : _currentValue(val), _defaultValue(val) {}
    ~Cell() {}
    void toDefault() { _currentValue = _defaultValue; } // очистка клетки
    void set_currentValue(int val) { _currentValue = val; }
    void set_defaultValue(int val) { _defaultValue = val; } //нужно чтобы забрать звезду
    int get_currentValue(){ return _currentValue; }

private:
    int _currentValue; // меняется, когда на клетку становится персонаж
    int _defaultValue; // что содержит клетка, когда на ней нет персонажей
};

#endif //OOP_CELL_H