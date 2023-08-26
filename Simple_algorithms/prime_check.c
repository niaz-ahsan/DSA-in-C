// Problem: https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=false&h_r=next-challenge&h_v=zen

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int cases;
    scanf("%d", &cases);
    int * collection = (int *) malloc(cases * sizeof(int));
    for (int i=0; i<cases; i++) {
        int num;
        scanf("%d", &num);
        collection[i] = num;
    }

    for (int i=0; i<cases; i++) {
        int num = collection[i];
        if (num == 1) {
            printf("Not prime\n");
            continue;
        } else if (num == 2) {
            printf("Prime\n");
            continue;
        }
        int limit = (double) sqrt((double) num);
        int is_prime = 1;
        for (int j=2; j<=limit; j++) {
            if (num % j == 0) {
                is_prime = 0;
                break;
            }
        }
        char * str = (is_prime)? "Prime" : "Not prime";
        printf("%s\n", str);
    }
    return 0;
}