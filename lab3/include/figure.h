#pragma once

#include <iostream>

using std::string;

class Figure {

public:
    virtual void geo_center_calc() const = 0;
    virtual double figure_square_calc() const = 0;

protected:
    string type;

};  