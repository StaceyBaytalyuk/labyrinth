#ifndef OOP_VISIBLE_H
#define OOP_VISIBLE_H
#include <iostream>

class Visible {
public:
    Visible() {}
    ~Visible() {}
    void show(){ _shown = true; }
    void hide(){ _shown = false; }
    bool isShown() { return _shown; }

private:
    bool _shown;
};

#endif //OOP_VISIBLE_H