#pragma once

#include <iostream>
#include "rectangle.h"

class Square: public Rectangle {
    friend std::istream& operator>>(std::istream& is, Square& s);

public:
    Square() {
        type = "Square";
        if(side1 != side2) {
            throw std::logic_error("invalid coordinates!");
        }
    }
    Square(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4) {
        
        x1 = _x1;
        x2 = _x2;
        x3 = _x3;
        x4 = _x4;
        y1 = _y1;
        y2 = _y2;
        y3 = _y3;
        y4 = _y4;

        double min_x = min(min(min(x1, x2), x3), x4);
        double max_x = max(max(max(x1, x2), x3), x4);

        double sum_x = x1 + x2 + x3 + x4;
        if((2*min_x + 2*max_x) != sum_x) {
            throw std::logic_error("invalid coordinates!");
        }

        x1 = min_x;
        x2 = min_x;
        x3 = max_x;
        x4 = max_x;

        double min_y = min(min(min(y1, y2), y3), y4);
        double max_y = max(max(max(y1, y2), y3), y4);

        double sum_y = y1 + y2 + y3 + y4;
        if((2*min_y + 2*max_y) != sum_y) {
            throw std::logic_error("invalid coordinates!");
        }

        y1 = min_y;
        y2 = max_y;
        y3 = max_y;
        y4 = min_y;

        side1 = y2 - y1;
        side2 = x4 - x1;

        type = "Square";

        if(side1 != side2) {
            throw std::logic_error("invalid coordinates!");
        }
    }

    Square operator=(Square& s) {

        x1 = s.x1;
        x2 = s.x2;
        x3 = s.x3;
        x4 = s.x4;
        y1 = s.y1;
        y2 = s.y2;
        y3 = s.y3;
        y4 = s.y4;

        side1 = s.side1;
        side2 = s.side2;

        side1 = side2;

        type = "Square";

        return *this;
    }
};

std::istream& operator>>(std::istream& is, Square& s) {
    std::cout << "SQUARE:" << endl;
    std::cout << "Input the coordinates of the first point" << std::endl;
    std::cout << "order [x1,y1], separated by spaces : ";
    
    is >> s.x1 >> s.y1;

    std::cout << "Input the coordinates of the second point" << std::endl;
    std::cout << "order [x2,y2], separated by spaces : ";

    is >> s.x2 >> s.y2;

    std::cout << "Input the coordinates of the third point" << std::endl;
    std::cout << "order [x3,y3], separated by spaces : ";

    is >> s.x3 >> s.y3;

    std::cout << "Input the coordinates of the fourth point" << std::endl;
    std::cout << "order [x4,y4], separated by spaces : ";

    is >> s.x4 >> s.y4;

    double min_x = min(min(min(s.x1, s.x2), s.x3), s.x4);
    double max_x = max(max(max(s.x1, s.x2), s.x3), s.x4);

    double sum_x = s.x1 + s.x2 + s.x3 + s.x4;
    if((2*min_x + 2*max_x) != sum_x) {
        throw std::logic_error("invalid coordinates!");
    }

    s.x1 = min_x;
    s.x2 = min_x;
    s.x3 = max_x;
    s.x4 = max_x;
    
    double min_y = min(min(min(s.y1, s.y2), s.y3), s.y4);
    double max_y = max(max(max(s.y1, s.y2), s.y3), s.y4);

    double sum_y = s.y1 + s.y2 + s.y3 + s.y4;
    if((2*min_y + 2*max_y) != sum_y) {
        throw std::logic_error("invalid coordinates!");
    }

    s.y1 = min_y;
    s.y2 = max_y;
    s.y3 = max_y;
    s.y4 = min_y;

    s.side1 = s.y2 - s.y1;
    s.side2 = s.x4 - s.x1;

    s.type = "Square";

    if(s.side1 != s.side2) {
        throw std::logic_error("invalid coordinates!");
    }
    return is;
}