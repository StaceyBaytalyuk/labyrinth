#ifndef OOP_CELL_H
#define OOP_CELL_H

class Cell {
public:
    Cell(int val) :
            _currentValue(val), _defaultValue(val)
    {}
    ~Cell() {}
    void toDefault() { _currentValue = _defaultValue; }
    void set_currentValue(int val) { _currentValue = val; }
    void set_defaultValue(int val) { _defaultValue = val; }
    int get_currentValue(){ return _currentValue; }

private:
    int _currentValue;
    int _defaultValue;
};

#endif //OOP_CELL_H