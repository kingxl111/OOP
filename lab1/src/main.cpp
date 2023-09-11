#include <iostream>
#include "foo.h"

using std::cin;
using std::cout;
using std::endl;

int main() {

    int up_speed, down_speed, desired_height;
    cout << "Input up speed: ";
    cin >> up_speed;
    cout << "Input down speed: ";
    cin >> down_speed;
    cout << "Input desired height: ";
    cin >> desired_height;
    
    int answer1 = time_calc(up_speed, down_speed, desired_height);
    cout << "Answer: " << answer1 << endl;

    // int answer2 = time_calc_prime(up_speed, down_speed, desired_height);
    // cout << "Answer: " <<  answer2 << endl;

    return 0;
}