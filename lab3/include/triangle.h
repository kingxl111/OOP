#pragma once

#include <iostream>
#include "figure.h"
#include <math.h>

class Triangle: public Figure {

    friend std::istream& operator>>(std::istream& is, Triangle& t);
    friend std::ostream& operator<<(std::ostream& os, Triangle& t);

public:
    Triangle();
    Triangle(Triangle& t);

    operator double() const; 

    double figure_square_calc() const override {
        double half_meter = (a + b + c) / 2;
        double sq = sqrt(half_meter * (half_meter - a) * (half_meter - b) * (half_meter - c));
        return sq;
    }



    void geo_center_calc() const override {

        double mid_x = (x1 + x2 + x3) / 3;
        double mid_y = (y1 + y2 + y3) / 3;

        std::cout << "Geo center: [ x : " << mid_x << ", y : " << mid_y << " ]" << std::endl;

    }


    ~Triangle() = default;

private:
    // Coordinates
    double x1;
    double y1;

    double x2;
    double y2;

    double x3;
    double y3;

    //Sides
    double a;
    double b;
    double c;


};

inline std::istream& operator>>(std::istream& is, Triangle& t) {

    std::cout << "Input the coordinates of the first point" << std::endl;
    std::cout << "order [x1,y1], separated by spaces : ";

    is >> t.x1 >> t.y1;

    std::cout << "Input the coordinates of the second point" << std::endl;
    std::cout << "order [x2,y2], separated by spaces : ";

    is >> t.x2 >> t.y2;

    std::cout << "Input the coordinates of the third point" << std::endl;
    std::cout << "order [x3,y3], separated by spaces : ";

    is >> t.x3 >> t.y3;

    double a = sqrt((t.x1 - t.x2)*(t.x1 - t.x2) + (t.y1 - t.y2)*(t.y1 - t.y2));
    double b = sqrt((t.x1 - t.x3)*(t.x1 - t.x3) + (t.y1 - t.y3)*(t.y1 - t.y3));
    double c = sqrt((t.x3 - t.x2)*(t.x3 - t.x2) + (t.y3 - t.y2)*(t.y3 - t.y2));

    t.a = a;
    t.b = b;
    t.c = c;

    return is;

}

inline std::ostream& operator<<(std::ostream& os, Triangle& t) {

    os << "Point1 [ x1 : " << t.x1 << ", y1 : " << t.y1 << " ]" << std::endl;
    os << "Point2 [ x2 : " << t.x2 << ", y2 : " << t.y2 << " ]" << std::endl;
    os << "Point3 [ x3 : " << t.x3 << ", y3 : " << t.y3 << " ]" << std::endl;


    return os;
}
