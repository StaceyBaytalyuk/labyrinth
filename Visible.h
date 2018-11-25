//
// Created by GERL on 22.11.2018.
//

#ifndef OOP_VISIBLE_H
#define OOP_VISIBLE_H


class Visible {
public:
    Visible() {}

    virtual ~Visible() {

    }
    void show(){ pokazivaetsia = true; }
    void hide(){ pokazivaetsia = false; }

    bool isShow() { return pokazivaetsia; }

private:
    bool pokazivaetsia;
};


#endif //OOP_VISIBLE_H
