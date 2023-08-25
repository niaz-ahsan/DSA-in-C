// Problem: https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=false

#include <stdio.h>
#include <stdlib.h>

int lib_fine(int ret_d, int ret_m, int ret_y, int due_d, int due_m, int due_y) {
    int fine = 0;
    int day_delay_multiple = 15;
    int month_delay_multiple = 500;
    int year_delay_multiple = 10000;

    if (ret_y > due_y) {
        return year_delay_multiple;
    } else if (ret_y == due_y) {
        // check month
        if (ret_m > due_m) {
            return month_delay_multiple * (ret_m - due_m);
        } else if (ret_m == due_m) {
            // check day
            if (ret_d > due_d) {
                return day_delay_multiple * (ret_d - due_d);
            }
        } else {
            return fine;
        }
    } else {
        return fine;
    }
    return fine;
}

int main() {
    int ret_d;
    int ret_m;
    int ret_y;
    int due_d;
    int due_m;
    int due_y;
    scanf("%d %d %d", &ret_d, &ret_m, &ret_y);
    scanf("%d %d %d", &due_d, &due_m, &due_y);
    printf("%d\n", lib_fine(ret_d, ret_m, ret_y, due_d, due_m, due_y));
    return 0;
}