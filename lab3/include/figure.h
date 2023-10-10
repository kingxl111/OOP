#pragma once

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Figure {

public:
    virtual void geo_center_calc() const = 0;
    virtual double figure_square_calc() const = 0;

    string get_type() {
        return type;
    }

protected:
    string type;

};  