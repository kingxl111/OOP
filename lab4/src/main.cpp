#include <iostream>
#include "figure.h"
#include "triangle.h"
#include "rectangle.h"
#include "square.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    
    try {
        // Square<int> s(1,1,2,2,1,2,2,1);
        // cout << s << endl;

        // Rectangle<double> r(1, 1, 3, 5, 1, 5, 3, 1);
        // cout << r << endl;  

        // Triangle<float> t(1, 2, 6, 3, 5, 10);
        // cout << t;

        Triangle<double> tr;
        cin >> tr;
        cout << tr << endl;

        double square = tr;
        cout << square << endl;
        
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}