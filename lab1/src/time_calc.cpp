#include <iostream>
#include "time_calc.h"

int time_calc(int up_speed, int down_speed, int desired_height) {
    
    if (desired_height == 0) {
        return 0;
    }
    if (up_speed == down_speed) {
        return -1;
    }
    int ans = (desired_height - down_speed) / (up_speed - down_speed);

    if ((ans < 0) || (ans * (up_speed - down_speed) + down_speed != desired_height)) {
        return -1;
    }
    
    return ans;
}

int time_calc_prime(int up_speed, int down_speed, int desired_height) {

    if (desired_height == 0) {
        return 0;
    }
    if ((up_speed == down_speed) || (up_speed < 0) || (down_speed < 0) || (desired_height < 0)) {
        return -1;
    }
    int height {0};
    int answer {0};
    while(true) {
        height += up_speed;
        ++answer;
        if(height == desired_height) {
            return answer;
        }
        else if (height > desired_height) {
            return -1;
        }
        height -= down_speed;
    }
}