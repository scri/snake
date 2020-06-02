//
// Created by Dragon on 2020/5/27.
//
#include "../include/point.h"

Point::Point() {

}
Point::Point(const int x, const int y):x(x),y(y) {

}
Point::~Point() {

}
void Point::pPrint() {
    Tool::setCurPos((bis + x)*2, y);
    cout << "¡ö";
}
void Point::pPrintCir() {
    Tool::setCurPos((bis + x)*2, y);
    cout << "¡ñ";
}
void Point::pClear() {
    Tool::setCurPos((bis + x)*2, y);
    cout << "  ";
}
void Point::setType(Type _type) {
    type = _type;
}

Point::Type Point::getType() const {
    return type;
}

bool Point::operator==(const Point &A) const {
    //cout << "here" << endl;
    return (A.x == this->x) && (A.y == this->y);
}
const int Point::getX() {
    return x;
}
const int Point::getY(){
    return y;
}