//
// Created by Dragon on 2020/5/27.
//

#include "../include/map.h"

Map::Map(const int colCnt_, const int rowCnt_):content(rowCnt_, std::vector<Point>(colCnt_)){
    //Tool::setWinSize(colCnt_, rowCnt_);
    //size = (rowCnt_ - 2) * (colCnt_ - 2);
    int row = getRow(), col = getCol();
    for(int i = 0; i < row; ++i){
        if(i == 0 || i == row - 1) {
            for (int j = 0; j < col; ++j) {
                content[i][j].setType(Point::Type::WALL);
            }
        }
        else{
            content[i][0].setType(Point::Type::WALL);
            content[i][col - 1].setType(Point::Type::WALL);
        }
    }
}
Map::~Map() {

}
void Map::startMap() {

}
void Map::selectMap() {

}
int Map::getCol() {
    return content[0].size();
}
int Map::getRow() {
    return content.size();
}
Point& Map::getPoint(int col, int row){
    return content[row][col];
}