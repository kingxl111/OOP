#include <iostream>
#include "triangle.h"
#include "square.h"
#include "rectangle.h"

using std::cin;
using std::cout;
using std::endl;

#define FIGURE_COUNT 3

// Треугольник Квадрат Прямоугольник

int main() {

    try {

        Figure** figs = new Figure* [FIGURE_COUNT];

        Triangle t1;
        cin >> t1;
        double sq1 = t1; // square of triangle t
        cout << "Triangle square: " << sq1 << endl;
        double sq2 = t1.figure_square_calc();
        cout << "Triangle square: " << sq2 << endl;
        t1.geo_center_calc();

        Triangle t2 = t1;
        cout << t2;

        bool eq1 = (t1 == t2);
        cout <<  "eq1: "<< eq1 << endl;

        Square s1;
        cin >> s1;
        sq1 = s1; // square of square s1
        cout << "Square's square: " << sq1 << endl;
        s1.geo_center_calc();

        Square s2 = s1;
        cout << s2;

        bool eq2 = (s1 == s2);
        cout <<  "eq2: "<< eq2 << endl;

        Rectangle r1;
        cin >> r1;
        sq1 = r1; // square of square s1
        cout << "Rectangle's square: " << sq1 << endl;
        s1.geo_center_calc();

        Rectangle r2 = r1;
        cout << r2;

        bool eq3 = (r1 == r2);
        cout <<  "eq3: "<< eq3 << endl << endl;


        cout << "///////////////////////////////////////////////////////" << endl << endl;

        double total_sq = 0;

        figs[0] = &t1;
        figs[1] = &s1;
        figs[2] = &r1;

        for(int i = 0; i < FIGURE_COUNT; ++i) {
            figs[i]->geo_center_calc();
            double sq = figs[i]->figure_square_calc();
            cout << figs[i]->get_type() << " square: " << sq << endl;
            total_sq += sq;
        }

        cout << "total square: " << total_sq << endl;
    } 
    catch(...) {
        cout << "Invalid input data!" << endl;
    }


    return 0;
}