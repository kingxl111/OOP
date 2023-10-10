#pragma once

#include <iostream>
#include "rectangle.h"

class Square: public Rectangle {

public:
    Square() {
        type = "Square";
        side1 = side2;
    }

    Square operator=(Square& r) {

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

        side1 = side2;

        type = "Square";

        return *this;
    }
};