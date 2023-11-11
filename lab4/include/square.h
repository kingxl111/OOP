#pragma once

#include <iostream>
#include "rectangle.h"

template<typename T>
class Square: public Rectangle<T> {
public:
    using vertex_t = std::pair<T,T>;

    std::istream& operator>>(std::istream& is) override{
        std::cout << "Input the coordinates of the first point" << std::endl;
        std::cout << "order [x1,y1], separated by spaces : ";

        is >> this->v1.first >> this->v1.second;

        std::cout << "Input the coordinates of the second point" << std::endl;
        std::cout << "order [x2,y2], separated by spaces : ";

        is >> this->v2.first >> this->v2.second;

        std::cout << "Input the coordinates of the third point" << std::endl;
        std::cout << "order [x3,y3], separated by spaces : ";

        is >> this->v3.first >> this->v3.second;

        std::cout << "Input the coordinates of the fourth point" << std::endl;
        std::cout << "order [x4,y4], separated by spaces : ";

        is >> this->v4.first >> this->v4.second;

        T min_x = min(min(min(this->v1.first, this->v2.first), this->v3.first), this->v4.first);
        T max_x = max(max(max(this->v1.first, this->v2.first), this->v3.first), this->v4.first);

        T sum_x = this->v1.first + this->v2.first + this->v3.first + this->v4.first;
        if((2*min_x + 2*max_x) != sum_x) {
            throw std::logic_error("invalid coordinates!");
        }

        this->v1.first = min_x;
        this->v2.first = min_x;
        this->v3.first = max_x;
        this->v4.first = max_x;
        
        T min_y = min(min(min(this->v1.second, this->v2.second), this->v3.second), this->v4.second);
        T max_y = max(max(max(this->v1.second, this->v2.second), this->v3.second), this->v4.second);

        T sum_y = this->v1.second + this->v2.second + this->v3.second + this->v4.second;
        if((2*min_y + 2*max_y) != sum_y) {
            throw std::logic_error("invalid coordinates!");
        }

        this->v1.second = min_y;
        this->v2.second = max_y;
        this->v3.second = max_y;
        this->v4.second = min_y;
        
        this->side1 = this->v2.second - this->v1.second;
        this->side2 = this->v4.first - this->v1.first;

        if(this->side1 != this->side2) {
            throw std::logic_error("invalid coordinates!");
        }

        return is;
    }

    Square() {
        if(this->side1 != this->side2) {
            throw std::logic_error("invalid coordinates!");
        }
    }
    Square(T _x1, T _y1, T _x2, T _y2, T _x3, T _y3, T _x4, T _y4) {
        this->v1.first = _x1;
        this->v1.second = _y1;
        this->v2.first = _x2;
        this->v2.second = _y2;
        this->v3.first = _x3;
        this->v3.second = _y3;
        this->v4.first = _x4;
        this->v4.second = _y4;

        T min_x = min(min(min(this->v1.first, this->v2.first), this->v3.first), this->v4.first);
        T max_x = max(max(max(this->v1.first, this->v2.first), this->v3.first), this->v4.first);

        T sum_x = this->v1.first + this->v2.first + this->v3.first + this->v4.first;
        if((2*min_x + 2*max_x) != sum_x) {
            throw std::logic_error("invalid coordinates!");
        }

        this->v1.first = min_x;
        this->v2.first = min_x;
        this->v3.first = max_x;
        this->v4.first = max_x;
        
        T min_y = min(min(min(this->v1.second, this->v2.second), this->v3.second), this->v4.second);
        T max_y = max(max(max(this->v1.second, this->v2.second), this->v3.second), this->v4.second);

        T sum_y = this->v1.second + this->v2.second + this->v3.second + this->v4.second;
        if((2*min_y + 2*max_y) != sum_y) {
            throw std::logic_error("invalid coordinates!");
        }

        this->v1.second = min_y;
        this->v2.second = max_y;
        this->v3.second = max_y;
        this->v4.second = min_y;
        
        this->side1 = this->v2.second - this->v1.second;
        this->side2 = this->v4.first - this->v1.first;

        // std::cout << this->this->side1 << " " << this->side2 << std::endl;

        if(this->side1 != this->side2) {
            throw std::logic_error("invalid coordinates!");
        }

    }

};
