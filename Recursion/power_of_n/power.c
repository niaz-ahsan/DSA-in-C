/*
n ^ m = ?
5 ^ 2 	    5 × 5 	    25
5 ^ 1 	    5 	        5
5 ^ 0 	    1 	        1
5 ^ -1 	    1/5 	    0.2
5 ^ -2 	    1/5 × 1/5 	0.04
*/

#include <stdio.h>
#include <stdlib.h>

// recursive approach
double power_of(int base, int power) {
    if (power == 1) {
        return base;
    } else if (power == 0) {
        return 1;
    }
    return (power > 0)? (base * power_of(base, power-1)) : (1 / power_of(base, (-1) * power));
}

// iterative approach
double iter_power_of(int base, int power) {
    double output = 1;
    int i;
    int limit = (power > 0)? power : (-1) * power; 
    for (i=0; i<limit; i++) {
        output = (power > 0)? (output * base) : (output * 1/base); 
    }
    return output;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Syntax: <exe> <base n> <power m>\n");
        exit(1);
    }
    int n = atoi(argv[1]); // converting param to int which is the n
    int m = atoi(argv[2]);

    printf("[Recursive] %d ^ %d = %lf\n", n, m, power_of(n, m));
    printf("[Iterative] %d ^ %d = %lf\n", n, m, iter_power_of(n, m));
    return 0;
}