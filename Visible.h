#ifndef OOP_VISIBLE_H
#define OOP_VISIBLE_H

#include <iostream>

class Visible {
public:
    Visible() {std::cout << "Visible created!"<<std::endl;}
    virtual ~Visible() {std::cout << "Visible deleted!"<<std::endl;}
    void show(){ _shown = true; }
    void hide(){ _shown = false; }
    bool isShown() { return _shown; }

private:
    bool _shown;
};

#endif //OOP_VISIBLE_H