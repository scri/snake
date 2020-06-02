//
// Created by Dragon on 2020/5/27.
//

#include "../include/snake.h"
#include "../include/food.h"

Snake::Snake(){

}
Snake::~Snake(){

}
void Snake::initSnake(Map *const m){
    setMap(m);
    int col = map -> getCol();
    int row = map -> getRow();
    for(int i = 0; i < 3; ++i){
        snake.emplace_back(col / 2 +i, row / 2);
    }
    for (auto& point : snake)
    {
        point.pPrintCir();
    }
}
bool Snake::isDead() {
    //hitSelfOrWall();
    return dead;
}
void Snake::hitSelfOrWall(){
    int cnt = 0;
    Point *head = new Point(snake.back().getX(), snake.back().getY());
    for (auto& point : snake)
    {
        if ( !(point == *head) )
            ++cnt;
        else
            break;
    }
    if(cnt == snake.size())
        dead = true;
    else
        dead = false;
    int col = head -> getX();
    int row = head -> getY();
    Point &point = map ->getPoint(col, row);
    if(point.getType() == Point::WALL){
        dead = true;
    }
    delete head;

}
void Snake::move() {
    if(isDead() || direction == NONE){
        return ;
    }
    switch (direction){
        case UP:
            snake.emplace_back(Point(snake.back().getX(), snake.back().getY() - 1 ));
            break;
        case DOWN:
            snake.emplace_back(Point(snake.back().getX(), snake.back().getY() + 1 ));
            break;
        case LEFT:
            snake.emplace_back(Point(snake.back().getX() - 1, snake.back().getY()));
            break;
        case RIGHT:
            snake.emplace_back(Point(snake.back().getX() + 1, snake.back().getY()));
            break;
        default:
            break;
    }
    //cout << snake.back().getX() << endl;
    snake.back().pPrintCir();
}
void Snake::moveSnake(){
    move();
    snake.front().pClear();
    snake.pop_front();
}
void Snake::addBody() {

}
void Snake::setMap(Map *const m) {
    map = m;
}
void Snake::keyBoard() {
    if(Tool::myKbhit()){
        switch (Tool::getCh()){
            case 72:
                if (direction != DOWN)
                    direction = UP;
                break;
            case 80:
                if (direction != UP)
                    direction = DOWN;
                break;
            case 75:
                if (direction != RIGHT)
                    direction = Direction::LEFT;
                break;
            case 77:
                if (direction != LEFT)
                    direction = RIGHT;
                break;
            case 27:  // Esc

                break;
            default:
                break;
        }
    }
}
bool Snake::isGetFood(const int x,const int y) {
    if(snake.back().getX() == x && snake.back().getY() == y){
        //cout << "here" << endl;
        return true;
    }else{
        return false;
    }
}
bool Snake::getBigFood() {

}