#include <iostream>
#include "time_calc.h"

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

    if(answer1 == -1) {
        cout << "Invalid input data!" << endl;
        exit(-1);
    }

    cout << "Answer: " << answer1 << endl;

    return 0;
}