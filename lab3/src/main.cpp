#include <iostream>
#include "triangle.h"


using std::cin;
using std::cout;
using std::endl;

// Треугольник Квадрат Прямоугольник

int main() {

    Triangle t;
    cin >> t;
    double sq = t; // square of triangle t
    cout << "Triangle square: " << sq << endl;
    double sq2 = t.figure_square_calc();
    cout << "Triangle square: " << sq2 << endl;
    t.geo_center_calc();



    

    return 0;
}