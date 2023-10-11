#pragma once

#include <iostream>
#include "figure.h"
#include <math.h>

class Triangle: public Figure {

    friend std::istream& operator>>(std::istream& is, Triangle& t);
    friend std::ostream& operator<<(std::ostream& os, Triangle& t);
    friend bool operator==(Triangle& s1, Triangle& s2);

public:
    Triangle();
    Triangle(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3);

    operator double() const; 

    Triangle operator=(Triangle& t) {

        x1 = t.x1;
        x2 = t.x2;
        x3 = t.x3;
        y1 = t.y1;
        y2 = t.y2;
        y3 = t.y3;
        side1 = t.side1;
        side2 = t.side2;
        side3 = t.side3;
        type = t.type;
        
        return *this;
    }

    virtual double figure_square_calc() const override {
        double half_meter = (side1 + side2 + side3) / 2;
        double sq = sqrt(half_meter * (half_meter - side1) * (half_meter - side2) * (half_meter - side3));
        return sq;
    }

    virtual void geo_center_calc() override {

        double mid_x = (x1 + x2 + x3) / 3;
        double mid_y = (y1 + y2 + y3) / 3;
        this->geo_center_x = mid_x;
        this->geo_center_y = mid_y;
        // std::cout << type  <<  " geo center: [ x : " << mid_x << ", y : " << mid_y << " ]" << std::endl;

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
    double side1;
    double side2;
    double side3;


};

inline std::istream& operator>>(std::istream& is, Triangle& t) {

    std::cout << "TRIANGLE:" << endl;
    std::cout << "Input the coordinates of the first point" << std::endl;
    std::cout << "order [x1,y1], separated by spaces : ";

    is >> t.x1 >> t.y1;

    std::cout << "Input the coordinates of the second point" << std::endl;
    std::cout << "order [x2,y2], separated by spaces : ";

    is >> t.x2 >> t.y2;

    std::cout << "Input the coordinates of the third point" << std::endl;
    std::cout << "order [x3,y3], separated by spaces : ";

    is >> t.x3 >> t.y3;

    double side1 = sqrt((t.x1 - t.x2)*(t.x1 - t.x2) + (t.y1 - t.y2)*(t.y1 - t.y2));
    double side2 = sqrt((t.x1 - t.x3)*(t.x1 - t.x3) + (t.y1 - t.y3)*(t.y1 - t.y3));
    double side3 = sqrt((t.x3 - t.x2)*(t.x3 - t.x2) + (t.y3 - t.y2)*(t.y3 - t.y2));

    t.side1 = side1;
    t.side2 = side2;
    t.side3 = side3;

    return is;

}

inline std::ostream& operator<<(std::ostream& os, Triangle& t) {

    os << "Point1 [ x1 : " << t.x1 << ", y1 : " << t.y1 << " ]" << std::endl;
    os << "Point2 [ x2 : " << t.x2 << ", y2 : " << t.y2 << " ]" << std::endl;
    os << "Point3 [ x3 : " << t.x3 << ", y3 : " << t.y3 << " ]" << std::endl;


    return os;
}
