#include <iostream>
#include <memory>
#include "figure.h"
#include "triangle.h"
#include "rectangle.h"
#include "square.h"
#include "template_array.h"

using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

int main() {    
    
    using vertex_t = std::pair<double, double>;

    try {

        shared_ptr<Figure<double> > triangle_ptr(make_shared<Triangle<double>>(10, 0, 1, 4, 1, 0));
        (*triangle_ptr) << cout;
        
        cout << triangle_ptr->figure_square_calc() << endl;
        vertex_t geo = triangle_ptr->geo_center_calc();
        cout << geo.first << " " << geo.second << endl;

        Array<shared_ptr<Figure<double> > > array{
                                    make_shared<Triangle<double>>(1, 2, 3, 0, 10, 5),
                                    make_shared<Square<double>>(1, 1, 4, 4, 1, 4, 4, 1),
                                    make_shared<Rectangle<double>>(10, 1, 15, 1, 15, 3, 10, 3),
                                    make_shared<Triangle<double>>(0, 0, 5, 5, 3, 0)
                                };
        

        for(size_t i = 0;i < array.size(); ++i) {
            *(array[i]) << cout << endl;
        }

        Array<shared_ptr<Figure<double> > > array2 = array;

        std::cout << "Print array2 ------------------------------" << endl;

        double total_square = 0;
        for(size_t i = 0; i < array2.size(); ++i) {
            array2[i]->print(cout);
            vertex_t cur_geo_center = array2[i]->geo_center_calc();
            cout << "Geo_center:\n x: " << cur_geo_center.first << ", y: " <<  cur_geo_center.second << endl;
            cout << "Current figure square = " << array2[i]->figure_square_calc();
            cout << endl << endl;
            total_square += array2[i]->figure_square_calc();
        }

        Array<shared_ptr<Figure<double>>> array3 = move(array2);
        cout << "Print array3 ------------------------------" << endl;

        for(size_t i = 0;i < array3.size(); ++i) {
            // (*array3[i]) << cout << endl;
            array3[i]->print(cout);
            cout << endl;
        }

        size_t rm_idx;
        cout << "Enter the index to remove the figure from array: ";
        cin >> rm_idx;
        
        array.remove(rm_idx);
        // cout << "Ok!" << endl;
        for(size_t i = 0; i < array.size(); ++i) {
            array[i]->print(cout);
            cout << endl;
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}