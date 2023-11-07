#pragma once

#include <iostream>

template<typename T>
class Figure {
public:

    using vertex_t = std::pair<T,T>;

    virtual vertex_t geo_center_calc() = 0;
    virtual T figure_square_calc() const = 0;
    
    vertex_t get_geo_center() {
        return geo_center;
    }

    vertex_t geo_center;
};  