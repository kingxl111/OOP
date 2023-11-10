#pragma once

#include <iostream>
#include "figure.h"
#include <math.h>

template<typename T>
class Triangle: public Figure<T> {

public:
    using vertex_t = std::pair<T,T>;

    std::istream& operator>>(std::istream& is) override{

        std::cout << "Input the coordinates of the first point" << std::endl;
        std::cout << "order [x1,y1], separated by spaces : ";

        is >> v1.first >> v1.second;

        std::cout << "Input the coordinates of the second point" << std::endl;
        std::cout << "order [x2,y2], separated by spaces : ";

        is >> v2.first >> v2.second;

        std::cout << "Input the coordinates of the third point" << std::endl;
        std::cout << "order [x3,y3], separated by spaces : ";

        is >> v3.first >> v3.second;

        T side1 = sqrt((v1.first - v2.first)*(v1.first - v2.first) + (v1.second - v2.second)*(v1.second - v2.second));
        T side2 = sqrt((v1.first - v3.first)*(v1.first - v3.first) + (v1.second - v3.second)*(v1.second - v3.second));
        T side3 = sqrt((v3.first - v2.first)*(v3.first - v2.first) + (v3.second - v2.second)*(v3.second - v2.second));

        side1 = side1;
        side2 = side2;
        side3 = side3;

        return is;
    }

    std::ostream& operator<<(std::ostream& os) override{
        os << "Point1 [ x1 : " << v1.first << ", y1 : " << v1.second << " ]" << std::endl;
        os << "Point2 [ x2 : " << v2.first << ", y2 : " << v2.second << " ]" << std::endl;
        os << "Point3 [ x3 : " << v3.first << ", y3 : " << v3.second << " ]" << std::endl;

        return os;
    }

    Triangle() {
        v1.first = 0;
        v1.second = 0;
        v2.first = 0;
        v2.second = 0;
        v3.first = 0;
        v3.second = 0;
        side1 = 0;
        side2 = 0;
        side3 = 0;
    }
    Triangle(T _x1, T _y1, T _x2, T _y2, T _x3, T _y3) {
        v1.first = _x1;
        v1.second = _y1;
        v2.first = _x2;
        v2.second = _y2;
        v3.first = _x3;
        v3.second = _y3;


        T side1 = sqrt((v1.first - v2.first)*(v1.first - v2.first) + (v1.second - v2.second)*(v1.second - v2.second));
        T side2 = sqrt((v1.first - v3.first)*(v1.first - v3.first) + (v1.second - v3.second)*(v1.second - v3.second));
        T side3 = sqrt((v3.first - v2.first)*(v3.first - v2.first) + (v3.second - v2.second)*(v3.second - v2.second));

        this->side1 = side1 ;
        this->side2 = side2;
        this->side3 = side3;
    }

    operator double() {
        T sq = figure_square_calc();
        return static_cast<double>(sq);
    }

    Triangle operator=(Triangle<T>& t) {

        v1.first = t.v1.first;
        v2.first = t.v2.first;
        v3.first = t.v3.first;
        v1.second = t.v1.second;
        v2.second = t.v2.second;
        v3.second = t.v3.second;
        side1 = t.side1;
        side2 = t.side2;
        side3 = t.side3;
        
        return *this;
    }

    virtual T figure_square_calc() const override {
        T half_meter = (side1 + side2 + side3) / 2;
        T sq = sqrt(half_meter * (half_meter - side1) * (half_meter - side2) * (half_meter - side3));
        return sq;
    }

    virtual vertex_t geo_center_calc() override {

        vertex_t mid;

        T mid_x = (v1.first + v2.first + v3.first) / 3;
        T mid_y = (v1.second + v2.second + v3.second) / 3;
        mid.first = mid_x;
        mid.second = mid_y;
        this->geo_center = mid;

        return mid;
    }

    ~Triangle() = default;

private:
    // Coordinates
    vertex_t v1;
    vertex_t v2;
    vertex_t v3;
    vertex_t v4;

    //Sides
    T side1;
    T side2;
    T side3;
};


