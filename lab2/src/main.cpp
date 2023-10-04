#include <iostream>
#include "octal.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {


    string s1, s2;
    cout << "Input n1: ";
    cin >> s1;
    cout << "Input n2: ";
    cin >> s2;

    try {
        Octal n1(s1);
        cout << "n1: ";
        n1.print(); 
        Octal n2(s2);
        cout << "n2: ";
        n2.print();

        Octal n3 = n1 + n2;
        Octal n4 = n1 - n2;
        cout << "n1 + n2 == ";
        n3.print();
        cout << "n1 - n2 == ";
        n4.print();

        cout << "n1 == n2: " << n1.equals(n2) << endl; 
    } catch (...) {
        std::cerr << "exception: " << endl;
    }
    



    return 0;
}