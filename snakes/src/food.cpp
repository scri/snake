//
// Created by Dragon on 2020/5/27.
//

#include "../include/food.h"

Food::Food(){

}
Food::~Food(){

}
Food::Food(const int _col, const int _row):col(_col),row(_row){

}
void Food::drawFood(Snake& snake) {
    while(1){
        srand((unsigned)time(NULL));
        int temp_x = x;
        int temp_y = y;
        x = rand() % col-1;
        y = rand() % row-1;
        if(x < 2) x += 2;
        if(y < 2) y += 2;
        bool flag = false;
        for (auto& point : snake.snake)
        {
            if ((point.getX() == x && point.getY() == y) || (x == temp_x && y == temp_y))
            {
                flag = true;
                break;
            }
        }
        if (flag){
            continue;
        }
        food = new Point(x, y);
        Tool::setCurPos(x, y);
        food ->pPrint();
        delete food;
        break;
    }
}
Point* Food::getFood() {
    return food;
}
const int Food::getX() {
    return x;
}
const int Food::getY(){
    return y;
}