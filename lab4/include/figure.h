#pragma once

#include <iostream>

template<typename T>
class Figure {
public:
    using vertex_t = std::pair<T,T>;

    virtual vertex_t geo_center_calc() = 0;
    virtual T figure_square_calc() const = 0;
    
    virtual std::ostream& operator<< (std::ostream& os) = 0;
    virtual std::istream& operator>>(std::istream& is) = 0;
    
    virtual std::ostream& print(std::ostream& os) = 0;

    vertex_t geo_center;
};  