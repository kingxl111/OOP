#include <iostream>
#include "triangle.h"

Triangle::Triangle(): x1(0), x2(0), x3(0), y1(0), y2(0), y3(0), side1(0), side2(0), side3(0) {
    type = "Triangle";
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