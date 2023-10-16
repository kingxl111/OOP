#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(): x1(0), x2(0), x3(0), x4(0), y1(0), y2(0), y3(0), y4(0), side1(0), side2(0) {}

Rectangle::Rectangle(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4) {
    
    this->x1 = _x1;
    this->y1 = _y1;
    this->x2 = _x2;
    this->y2 = _y2;
    this->x3 = _x3;
    this->y3 = _y3;
    this->x4 = _x4;
    this->y4 = _y4;

    double min_x = min(min(min(x1, x2), x3), x4);
    double max_x = max(max(max(x1, x2), x3), x4);

    double sum_x = x1 + x2 + x3 + x4;
    if((2*min_x + 2*max_x) != sum_x) {
        throw std::logic_error("invalid coordinates!");
    }

    this->x1 = min_x;
    this->x2 = min_x;
    this->x3 = max_x;
    this->x4 = max_x;
    
    double min_y = min(min(min(y1, y2), y3), y4);
    double max_y = max(max(max(y1, y2), y3), y4);

    double sum_y = y1 + y2 + y3 + y4;
    if((2*min_y + 2*max_y) != sum_y) {
        throw std::logic_error("invalid coordinates!");
    }

    this->y1 = min_y;
    this->y2 = max_y;
    this->y3 = max_y;
    this->y4 = min_y;

    this->side1 = y2 - y1;
    this->side2 = x4 - x1;
}


Rectangle::operator double() const {
    return figure_square_calc();
}

bool operator==(Rectangle& r1, Rectangle& r2) {
    if((r1.x1 == r2.x1) && (r1.x2 == r2.x2) && (r1.x3 == r2.x3) && (r1.x4 == r2.x4)
    && (r1.y1 == r2.y1) && (r1.y2 == r2.y2) && (r1.y3 == r2.y3) && (r1.y4 == r2.y4)) {
        return true;
    }
    return false;
}

