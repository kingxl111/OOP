#pragma once

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Figure {

public:
    virtual void geo_center_calc() = 0;
    virtual double figure_square_calc() const = 0;
    
    double get_geo_center_x() {
        return geo_center_x;
    }
    double get_geo_center_y() {
        return geo_center_y;
    }

protected:
    double geo_center_x;
    double geo_center_y;
};  