/*
1 * 2 * 3 * ..... * (n-1) * n = ?
*/

#include <stdio.h>
#include <stdlib.h>

// recursive approach O(n)
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } 
    return n * factorial(n-1);
}

// iterative approach O(n)
int iter_factorial(int n) {
    int i;
    int output = 1;
    for (i=1; i<=n; i++) {
        output *= i;
    }
    return output;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Syntax: <exe> <int n>\n");
        exit(1);
    }
    int n = atoi(argv[1]); // converting param to int which is the n
    if (n < 0) {
        printf("arg must be +ve\n");
        exit(1);
    }

    printf("[Recusion] 1*2*3*....*%d = %d\n", n, factorial(n));
    printf("[Iteration] 1*2*3*....*%d = %d\n", n, iter_factorial(n));

    return 0;
}