#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(): x1(0), x2(0), x3(0), x4(0), y1(0), y2(0), y3(0), y4(0), side1(0), side2(0) {
    type = "Rectangle";
}

Rectangle::operator double() const {
    return figure_square_calc();
}

bool operator==(Rectangle& r1, Rectangle& r2) {
    if((r1.x1 == r2.x1) && (r1.x2 == r2.x2) && (r1.x3 == r2.x3) && (r1.x4 == r2.x4)
    && (r1.y1 == r2.y1) && (r1.y2 == r2.y2) && (r1.y3 == r2.y3) && (r1.y4 == r2.y4)
    && (r1.type == r2.type)) {
        return true;
    }
    return false;
}

