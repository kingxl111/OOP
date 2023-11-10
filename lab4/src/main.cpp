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

int main() {    
    
    using vertex_t = std::pair<double, double>;

    try {

        shared_ptr<Figure<double> > triangle_ptr(std::make_shared<Triangle<double>>(10, 0, 1, 4, 1, 0));
        (*triangle_ptr) << cout;
        
        cout << (*triangle_ptr).figure_square_calc() << endl;
        vertex_t geo = (*triangle_ptr).geo_center_calc();
        cout << geo.first << " " << geo.second << endl;

        // Array<shared_ptr<Figure<int> > > array{
        //                             std::make_shared<Triangle<int>>(),
        //                             std::make_shared<Square<int>>(),
        //                             std::make_shared<Rectangle<int>>(),
        //                             std::make_shared<Triangle<int>>()
        //                         };
        
        // for(size_t i=0;i<array.size();++i)
        // cout << *(array[i]) << endl;

        // cout << "Print ----------------" << endl;

        // for(size_t i=0;i<array.size();++i) {
        //     array[i]->print(cout);
        //     cout << endl;
        // }

        // Array<shared_ptr<Figure<int> > > array2 = array;

        // std::cout << "Print array2 ----------------" << endl;

        // for(size_t i=0;i<array2.size();++i) {
        //     array2[i]->print(std::cout);
        //     cout << endl;
        // }

        // Array<shared_ptr<Figure<int>>> array3 = move(array2);


        // cout << "Print array3 ----------------" << endl;

        // for(size_t i=0;i<array3.size();++i) {
        //     array3[i]->print(cout);
        //     cout << endl;
        // }


    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}