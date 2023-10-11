#include <iostream>
#include "triangle.h"

Triangle::Triangle(): x1(0), x2(0), x3(0), y1(0), y2(0), y3(0), side1(0), side2(0), side3(0) {
    type = "Triangle";
}

Triangle::Triangle(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3) {

    // cout << "The second triangle constructor!" << endl;

    this->x1 = _x1;
    this->y1 = _y1;
    this->x2 = _x2;
    this->y2 = _y2;
    this->x3 = _x3;
    this->y3 = _y3;

    double side1 = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    double side2 = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
    double side3 = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));

    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;

    this->type = "Triangle";
}


Triangle::operator double() const {
    return figure_square_calc();
}

bool operator==(Triangle& t1, Triangle& t2) {
    if((t1.x1 == t2.x1) && (t1.x2 == t2.x2) && (t1.x3 == t2.x3) 
    && (t1.y1 == t2.y1) && (t1.y2 == t2.y2) && (t1.y3 == t2.y3) 
    && (t1.type == t2.type)) {
        return true;
    }
    return false;
}