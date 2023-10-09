#include <iostream>
#include "triangle.h"

Triangle::Triangle(): x1(0), x2(0), x3(0), y1(0), y2(0), y3(0) {
    type = "triangle";
}

Triangle::Triangle(Triangle& t) {
    this->x1 = t.x1;
    this->x2 = t.x2;
    this->x3 = t.x3;

    this->y1 = t.y1;
    this->y2 = t.y2;
    this->y3 = t.y3;

    this->a = t.a;
    this->b = t.b;
    this->c = t.c;

    this->type = "triangle";
    
}

Triangle::operator double() const {
    return figure_square_calc();
}