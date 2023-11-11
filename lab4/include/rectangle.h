#pragma once

#include <iostream>
#include "figure.h"
#include <math.h>

using std::min;
using std::max;

template<typename T>
class Rectangle: public Figure<T> {

public:
    using vertex_t = std::pair<T,T>;

    std::ostream& operator<<(std::ostream& os) override{

        os << "Point1 [ x1 : " << v1.first << ", y1 : " << v1.second << " ]" << std::endl;
        os << "Point2 [ x2 : " << v2.first << ", y2 : " << v2.second << " ]" << std::endl;
        os << "Point3 [ x3 : " << v3.first << ", y3 : " << v3.second << " ]" << std::endl;
        os << "Point4 [ x4 : " << v4.first << ", y4 : " << v4.second << " ]" << std::endl;

        return os;
    
    }

    std::ostream& print(std::ostream& os) override {
        *this << os; 
        return os;   
    }

    std::istream& operator>>(std::istream& is) override {
        std::cout << "Input the coordinates of the first point" << std::endl;
        std::cout << "order [x1,y1], separated by spaces : ";

        is >> v1.first >> v1.second;

        std::cout << "Input the coordinates of the second point" << std::endl;
        std::cout << "order [x2,y2], separated by spaces : ";

        is >> v2.first >> v2.second;

        std::cout << "Input the coordinates of the third point" << std::endl;
        std::cout << "order [x3,y3], separated by spaces : ";

        is >> v3.first >> v3.second;

        std::cout << "Input the coordinates of the fourth point" << std::endl;
        std::cout << "order [x4,y4], separated by spaces : ";

        is >> v4.first >> v4.second;

        T min_x = min(min(min(v1.first, v2.first), v3.first), v4.first);
        T max_x = max(max(max(v1.first, v2.first), v3.first), v4.first);

        T sum_x = v1.first + v2.first + v3.first + v4.first;
        if((2*min_x + 2*max_x) != sum_x) {
            throw std::logic_error("invalid coordinates!");
        }

        v1.first = min_x;
        v2.first = min_x;
        v3.first = max_x;
        v4.first = max_x;
        
        T min_y = min(min(min(v1.second, v2.second), v3.second), v4.second);
        T max_y = max(max(max(v1.second, v2.second), v3.second), v4.second);

        T sum_y = v1.second + v2.second + v3.second + v4.second;
        if((2*min_y + 2*max_y) != sum_y) {
            throw std::logic_error("invalid coordinates!");
        }

        v1.second = min_y;
        v2.second = max_y;
        v3.second = max_y;
        v4.second = min_y;
        
        side1 = v2.second - v1.second;
        side2 = v4.first - v1.first;

        return is;
    }

    friend bool operator==(Rectangle<T> r1, Rectangle<T> r2) {
        int result = 1;      
        result *= (r1.v1.first == r2.v1.first);
        result *= (r1.v2.first == r2.v2.first);
        result *= (r1.v3.first == r2.v3.first);
        result *= (r1.v4.first == r2.v4.first);
        result *= (r1.v1.second == r2.v1.second);
        result *= (r1.v2.second == r2.v2.second);
        result *= (r1.v3.second == r2.v3.second);
        result *= (r1.v4.second == r2.v4.second);
        return static_cast<bool>(result);
    }

    Rectangle() {
        v1.first = 0;
        v1.second = 0;
        v2.first = 0;
        v2.second = 0;
        v3.first = 0;
        v3.second = 0;
        v4.first = 0;
        v4.second = 0;
        side1 = 0;
        side2 = 0;
    }
    Rectangle(T _x1, T _y1, T _x2, T _y2, T _x3, T _y3, T _x4, T _y4) {
        v1.first = _x1;
        v1.second = _y1;
        v2.first = _x2;
        v2.second = _y2;
        v3.first = _x3;
        v3.second = _y3;
        v4.first = _x4;
        v4.second = _y4;

        T min_x = min(min(min(v1.first, v2.first), v3.first), v4.first);
        T max_x = max(max(max(v1.first, v2.first), v3.first), v4.first);

        T sum_x = v1.first + v2.first + v3.first + v4.first;
        if((2*min_x + 2*max_x) != sum_x) {
            throw std::logic_error("invalid coordinates!");
        }

        v1.first = min_x;
        v2.first = min_x;
        v3.first = max_x;
        v4.first = max_x;
        
        T min_y = min(min(min(v1.second, v2.second), v3.second), v4.second);
        T max_y = max(max(max(v1.second, v2.second), v3.second), v4.second);

        T sum_y = v1.second + v2.second + v3.second + v4.second;
        if((2*min_y + 2*max_y) != sum_y) {
            throw std::logic_error("invalid coordinates!");
        }

        v1.second = min_y;
        v2.second = max_y;
        v3.second = max_y;
        v4.second = min_y;
        
        side1 = v2.second - v1.second;
        side2 = v4.first - v1.first;

    }

    operator double() {
        T sq = figure_square_calc();
        return static_cast<double>(sq);
    }

    Rectangle operator=(Rectangle<T>& r) {

        v1 = r.v1;
        v2 = r.v2;
        v3 = r.v3;
        v4 = r.v4;

        side1 = r.side1;
        side2 = r.side2;

        return *this;
    }

    virtual T figure_square_calc() const override {
        return side1 * side2;
    }

    virtual vertex_t geo_center_calc() override {

        vertex_t mid;
        mid.first = (v4.first + v1.first) / 2;
        mid.second = (v2.second + v1.second) / 2;
        this->geo_center = mid;
        return mid;
    }

    ~Rectangle() = default;

protected:
    // vertexes
    vertex_t v1;
    vertex_t v2;
    vertex_t v3;
    vertex_t v4;

    //Sides
    T side1;
    T side2;
};

