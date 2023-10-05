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
        try {

        Octal n1(s1);
        cout << "n1: ";
        n1.print(); 
        Octal n2(s2);
        cout << "n2: ";
        n2.print();
        cout << "n1 == n2: " << (n1 == n2) << endl; 

        Octal n3 = n1 + n2;
        Octal n4 = n1 - n2;
        cout << "n1 + n2 == ";
        n3.print();
        cout << "n1 - n2 == ";
        n4.print();

        } catch (string& ex) {
            std::cerr << "Exception: " << ex << endl;
        }


        Octal n5(80, '7');
        cout << "n5: ";
        n5.print();

        Octal n6("71274712747123432754623564135241270124472735472534651234516162415263126314256341");
        cout << "n6: ";
        n6.print();

        Octal n7 = n6 - n5;
        cout << "n6 - n5: ";
        n7.print();

        Octal n8(15, '0');
        cout << "n8: ";
        n8.print();

        Octal nn1(1, '0');
        Octal nn2("-0");
        Octal nn3 = nn1 - nn2;
        
        Octal n9("0");
        

        cout << "nn1: ";
        nn1.print();
        cout << "nn2: ";
        nn2.print();

        cout << "is_eq: " <<  (nn3 == n9) << endl;
        cout << "n9: ";
        n9.print();

    } catch (string& ex) {
        std::cerr << "Exception: " << ex << endl;
    }
    

    return 0;
}