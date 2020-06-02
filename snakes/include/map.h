//
// Created by Dragon on 2020/5/27.
//

#ifndef SNAKES_MAP_H
#define SNAKES_MAP_H
#include "../include/point.h"
#include "../include/tool.h"
#include <vector>
class Map{
public:
    Map(const int rowCnt_, const int colCnt_);
    ~Map();
    void startMap();                                // 开机动画
    void selectMap();                               //
    Point& getPoint(int col, int row);
    int getRow();
    int getCol();
private:
    std::vector<std::vector<Point>> content;

};



#endif //SNAKES_MAP_H
