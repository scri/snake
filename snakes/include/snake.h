//
// Created by Dragon on 2020/5/27.
//

#ifndef SNAKES_SNAKE_H
#define SNAKES_SNAKE_H

#include <vector>
#include <list>
#include "../include/point.h"
#include "../include/map.h"
#include "../include/direction.h"
using namespace std;
class Snake{
public:
    Snake();
    ~Snake();
    bool isDead();
    void move();
    void addBody();
    void setMap(Map *const m);
    void hitSelfOrWall();
    void initSnake(Map *const m);
    void moveSnake();
    void keyBoard();
    bool isGetFood(const int x, const int y);
    bool getBigFood();
    list<Point> snake;
    //void

private:
    Map *map = nullptr;
    //const int bis = 9;
    //list<Point> snake;
    bool dead = false;
    Direction direction = UP;
};

#endif //SNAKES_SNAKE_H
