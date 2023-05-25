/*
index   =     1 2 3 4 5 6 7 8  9
series  =     0 1 1 2 3 5 8 13 21 ...
*/

#include <stdio.h>
#include <stdlib.h>

// recursive approach without memoization
int fib(int n) {
    if (n <= 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    }
    int num = fib(n-1) + fib(n-2);
    return num;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Syntax: <exe> <nth term>\n");
        exit(1);
    }
    int n = atoi(argv[1]); // converting param to int which is the n
    printf("%d\n", fib(n));
    return 0;
}