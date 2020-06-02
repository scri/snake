//
// Created by Dragon on 2020/5/27.
//

#ifndef SNAKES_POINT_H
#define SNAKES_POINT_H

#include "../include/tool.h"
#include <iostream>
using namespace std;
class Point{
public:
    enum Type{
        EMPTY,
        WALL,
        FOOD
    };
public:
    Point();
    Point(const int x, const int y);
    ~Point();
    void pPrint();
    void pClear();
    void pPrintCir();
    void setType(Type _type);
    Type getType() const;
    bool operator==(const Point& A) const;
    const int getX();
    const int getY();

private:
    Type type = EMPTY;
    const int bis = 9;
    int x;
    int y;
};

#endif //SNAKES_POINT_H
