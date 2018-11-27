#ifndef OOP_CELL_H
#define OOP_CELL_H

class Cell {
public:
    Cell(int val);
    ~Cell();
    void toDefault();
    void set_currentValue(int val);
    void set_defaultValue(int val) { _defaultValue = val; }
    int get_currentValue(){ return _currentValue; }
    //возможно нужен геттер


private:
    int _currentValue;
    int _defaultValue;
};

#endif //OOP_CELL_H
