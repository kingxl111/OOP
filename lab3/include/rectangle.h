#pragma once

#include <iostream>
#include "figure.h"
#include <math.h>

using std::min;
using std::max;

class Rectangle: public Figure {

    friend std::istream& operator>>(std::istream& is, Rectangle& r);
    friend std::ostream& operator<<(std::ostream& os, Rectangle& r);
    friend bool operator==(Rectangle& r1, Rectangle& r2);

public:
    Rectangle();
    Rectangle(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4);

    operator double() const; 
    
    Rectangle operator=(Rectangle& r) {

        x1 = r.x1;
        x2 = r.x2;
        x3 = r.x3;
        x4 = r.x4;
        y1 = r.y1;
        y2 = r.y2;
        y3 = r.y3;
        y4 = r.y4;

        side1 = r.side1;
        side2 = r.side2;

        type = r.type;

        return *this;
    }

    virtual double figure_square_calc() const override {
        return side1 * side2;
    }

    virtual void geo_center_calc() override {

        double mid_x = (x4 + x1) / 2;
        double mid_y = (y2 + y1) / 2;
        this->geo_center_x = mid_x;
        this->geo_center_y = mid_y;
        // std::cout << type <<  " geo center: [ x : " << mid_x << ", y : " << mid_y << " ]" << std::endl;

    }

    ~Rectangle() = default;

protected:
    // Coordinates
    double x1;
    double y1;

    double x2;
    double y2;

    double x3;
    double y3;

    double x4;
    double y4;

    //Sides
    double side1;
    double side2;
};


inline std::istream& operator>>(std::istream& is, Rectangle& r) {

    std::cout << "RECTANGLE:" << endl;
    std::cout << "Input the coordinates of the first point" << std::endl;
    std::cout << "order [x1,y1], separated by spaces : ";

    is >> r.x1 >> r.y1;

    std::cout << "Input the coordinates of the second point" << std::endl;
    std::cout << "order [x2,y2], separated by spaces : ";

    is >> r.x2 >> r.y2;

    std::cout << "Input the coordinates of the third point" << std::endl;
    std::cout << "order [x3,y3], separated by spaces : ";

    is >> r.x3 >> r.y3;

    std::cout << "Input the coordinates of the fourth point" << std::endl;
    std::cout << "order [x4,y4], separated by spaces : ";

    is >> r.x4 >> r.y4;

    double min_x = min(min(min(r.x1, r.x2), r.x3), r.x4);
    double max_x = max(max(max(r.x1, r.x2), r.x3), r.x4);

    double sum_x = r.x1 + r.x2 + r.x3 + r.x4;
    if((2*min_x + 2*max_x) != sum_x) {
        throw std::logic_error("invalid coordinates!");
    }

    r.x1 = min_x;
    r.x2 = min_x;
    r.x3 = max_x;
    r.x4 = max_x;
    
    double min_y = min(min(min(r.y1, r.y2), r.y3), r.y4);
    double max_y = max(max(max(r.y1, r.y2), r.y3), r.y4);

    double sum_y = r.y1 + r.y2 + r.y3 + r.y4;
    if((2*min_y + 2*max_y) != sum_y) {
        throw std::logic_error("invalid coordinates!");
    }

    r.y1 = min_y;
    r.y2 = max_y;
    r.y3 = max_y;
    r.y4 = min_y;

    r.side1 = r.y2 - r.y1;
    r.side2 = r.x4 - r.x1;

    r.type = "Rectangle";

    return is;

}

inline std::ostream& operator<<(std::ostream& os, Rectangle& r) {

    os << "Point1 [ x1 : " << r.x1 << ", y1 : " << r.y1 << " ]" << std::endl;
    os << "Point2 [ x2 : " << r.x2 << ", y2 : " << r.y2 << " ]" << std::endl;
    os << "Point3 [ x3 : " << r.x3 << ", y3 : " << r.y3 << " ]" << std::endl;
    os << "Point4 [ x4 : " << r.x4 << ", y4 : " << r.y4 << " ]" << std::endl;

    return os;
}