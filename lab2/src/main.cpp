#include <iostream>
#include "octal.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

    string s1, s2;
    cin >> s1;
    cin >> s2;

    Octal n1(s1);
    Octal n2(s2);

    // cout << "n1 greater than n2: " << n1.greater(n2) << endl;
    // cout << "n1 less than n2: " << n1.less(n2) << endl;
    // cout << "n1 equals n2: " << n1.equals(n2) << endl;

    Octal n3 = n1.add(n2);
    n3.print();

    return 0;
}