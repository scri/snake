//
// Created by Dragon on 2020/5/27.
//

#include "../include/ctrl.h"

#include <iostream>
using namespace std;
Ctrl::Ctrl() {
    //cout << "here" << endl;
    //col = 10;
}
Ctrl::~Ctrl() {

}
void Ctrl::start() {
    map = new Map(mapCol + m, mapRow);
    drawGame(0,0);
    Tool::setCurPos(2,mapRow/2);
    cout << "                         Snake Game       " << endl;
    Tool::setCurPos(2,mapRow/2+1);
    cout <<"                   Press any key to start... "<<endl;
    char temp = Tool::getCh();
    //system("pause");
    delete map;
}
void Ctrl::select() {
    map = new Map(mapCol+m, mapRow);
    drawGame(0,0);
    Tool::mySetColor(3);
    Tool::setCurPos(2,2);
    cout << "                 Please select the difficulty level:" << endl;
    Tool::mySetColor(2);
    Tool::setCurPos(2,4);
    cout << "                             easy" << endl;
    Tool::mySetColor(3);
    Tool::setCurPos(2,6);
    cout << "                            normal" << endl;
    Tool::mySetColor(3);
    Tool::setCurPos(2,8);
    cout << "                             hard" << endl;
    Tool::mySetColor(3);
    Tool::setCurPos(2,10);
    cout << "                          very hard" << endl;
    Tool::setCurPos(mapCol-1,mapRow-1);

    score = 0;
    char ch;
    //ch = Tool::getCh();
    bool flag = false;
    while(ch = Tool::getCh()){
        if(int(ch) == 13){
            break;
        }
        switch (ch)
        {
            case 72:
                if(key > 1){
                    switch (key){
                        case 2:
                            Tool::mySetColor(2);
                            Tool::setCurPos(2,4);
                            cout << "                             easy" << endl;
                            Tool::mySetColor(3);
                            Tool::setCurPos(2,6);
                            cout << "                            normal" << endl;
                            key --;
                            break;
                        case 3:
                            Tool::mySetColor(2);
                            Tool::setCurPos(2,6);
                            cout << "                            normal" << endl;
                            Tool::mySetColor(3);
                            Tool::setCurPos(2,8);
                            cout << "                             hard" << endl;
                            key --;
                            break;
                        case 4:
                            Tool::mySetColor(2);
                            Tool::setCurPos(2,8);
                            cout << "                             hard" << endl;
                            Tool::mySetColor(3);
                            Tool::setCurPos(2,10);
                            cout << "                          very hard" << endl;
                            key --;
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 80:
                if(key < 4){
                    switch (key){
                        case 1:
                            Tool::mySetColor(3);
                            Tool::setCurPos(2,4);
                            cout << "                             easy" << endl;
                            Tool::mySetColor(2);
                            Tool::setCurPos(2,6);
                            cout << "                            normal" << endl;
                            ++key;
                            break;
                        case 2:
                            Tool::mySetColor(3);
                            Tool::setCurPos(2,6);
                            cout << "                            normal" << endl;
                            Tool::mySetColor(2);
                            Tool::setCurPos(2,8);
                            cout << "                             hard" << endl;
                            key ++;
                            break;
                        case 3:
                            Tool::mySetColor(3);
                            Tool::setCurPos(2,8);
                            cout << "                             hard" << endl;
                            Tool::mySetColor(2);
                            Tool::setCurPos(2,10);
                            cout << "                          very hard" << endl;
                            key ++;
                            break;
                        default:
                            break;
                    }
                }
                break;
            default:
                break;
        }
    }
    switch (key){
        case 1:
            speed = 120;
            break;
        case 2:
            speed = 90;
            break;
        case 3:
            speed = 60;
            break;
        case 4:
            speed = 30;
            break;
        default:
            break;
    }
    delete map;
}
void Ctrl::game() {
    start();
    select();
    drawGameMap(0,0);
    playGame();
    //map = new Map(mapCol, mapRow);
}
void Ctrl::drawGame(const int x, const int y) {
    Tool::setCurPos(x, y);
    int col = map -> getCol();
    int row = map -> getRow();
    for(int i = 0; i < row; ++i){
        Tool::setCurPos(x, i);
        for(int j = 0; j < col; ++j){
            Point &point = map ->getPoint(j, i);
            switch (point.getType()){

                case Point::EMPTY:
                    //Tool::write("¡ö");
                    Tool::write("  ");
                    break;
                case Point::WALL:
                    //cout << i <<"," << j << endl;
                    Tool::write("--");
                    break;
                default:
                    break;
            }
        }
        Tool::write("\n");

    }

}
void Ctrl::drawGameMap(const int x, const int y) {
    Tool::clear();
    map = new Map(mapCol, mapRow);
    drawGame(m * 2, 0);
    Tool::setCurPos(0, 2);
    Tool::mySetColor(3);
    cout << "GREED SNAKE" ;
    Tool::setCurPos(0, 4);
    Tool::mySetColor(3);
    cout << "MODE:" ;
    Tool::setCurPos(0, 6);
    Tool::mySetColor(2);
    switch (key){
        case 1:
            cout <<"easy" ;
            break;
        case 2:
            cout <<"normal" ;
            break;
        case 3:
            cout <<"hard";
            break;
        case 4:
            cout <<"very hard" ;
            break;
        default:
            break;
    }
    Tool::setCurPos(0, 8);
    Tool::mySetColor(3);
    cout <<"score:" ;
    Tool::setCurPos(2, 10);
    cout << score << endl;
    //char ch = Tool::getCh();
    //delete map;
}

void Ctrl::updateScore() {
    Tool::setCurPos(2, 10);
    score += 1;
    cout << score << endl;
}
void Ctrl:: playGame(){
    Snake *s = new Snake();
    Food *food = new Food(mapCol, mapRow);
    //drawFood()
    srand((unsigned)time(NULL));
    food ->drawFood(*s);
    s -> initSnake(map);;
    while(!s->isDead()){
        s -> keyBoard();
        if(s -> isGetFood(food->getX(), food->getY())){
            s -> move();
            food -> drawFood(*s);
            updateScore();
        }else{
            s -> moveSnake();
        }
        s -> hitSelfOrWall();
        Sleep(speed);
    }
    int ch;
    ch = Tool::getCh();
    //s -> move();
}
void Ctrl::setMapSize(const int _col, const int _row) {
    mapCol = _col;
    mapRow = _row;
}
void Ctrl::setSpeed(const int _speed) {
    speed = _speed;
}
Ctrl* Ctrl::getInstance() {
    static Ctrl instance;
    return &instance;
}