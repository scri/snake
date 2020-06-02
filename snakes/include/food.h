//
// Created by Dragon on 2020/5/27.
//

#ifndef SNAKES_FOOD_H
#define SNAKES_FOOD_H

#include "../include/tool.h"
#include "../include/point.h"
#include "../include/snake.h"
#include <time.h>
#include <stdlib.h>
class Food{
public:
    Food();
    Food(const int _col, const int _row);
    ~Food();
    void drawFood(Snake& snake);
    const int getX();
    const int getY();
    Point* getFood();

private:
    Point* food = nullptr;
    int col;
    int row;
    int x = 0;
    int y = 0;
};
#endif //SNAKES_FOOD_H
