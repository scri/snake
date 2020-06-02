//
// Created by Dragon on 2020/5/27.
//
#ifndef SNAKES_CTRL_H
#define SNAKES_CTRL_H

#include "../include/map.h"
#include "../include/snake.h"
#include "../include/direction.h"
#include "../include/food.h"
#include "../include/tool.h"
#include <time.h>
#include <iostream>
using namespace std;
class Ctrl{
public:
    Ctrl();
    ~Ctrl();
    Ctrl* getInstance();
    void setSpeed(const int speed);
    void start();
    void select();
    void drawGame(const int x, const int y);
    void game();
    void setMapSize(const int _col,const  int _row);
    void drawGameMap(const int x, const int y);
    void updateScore();
    void playGame();


private:
    Map* map = nullptr;
    int speed = 120;
    int key = 1;
    const int m = 9;
    int mapRow = 25;
    int mapCol = 28;
    int score = 0;
};
#endif //SNAKES_CTRL_H
