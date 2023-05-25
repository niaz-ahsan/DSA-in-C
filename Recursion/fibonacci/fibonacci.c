/*
index   =     0 1 2 3 4 5 6 7  8
series  =     0 1 1 2 3 5 8 13 21 ...
*/

#include <stdio.h>
#include <stdlib.h>

// recursive approach
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    int num = fib(n-1) + fib(n-2);
    return num;
}

// recursive approach w/ memoization
// correct ans till fib(93)
unsigned long long fib_memoization(int n, unsigned long long * m) {
    if (m[n] != -1) {
        return m[n];
    } else if (n <= 1) {
        m[n] = n;
        return n;
    }
    unsigned long long num = fib_memoization(n-1, m) + fib_memoization(n-2, m);
    m[n] = num;
    return num;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Syntax: <exe> <nth term>\n");
        exit(1);
    }
    int n = atoi(argv[1]); // converting param to int which is the n
    unsigned long long memory[n];
    int i;
    for (i=0; i<=n; i++) {
        memory[i] = -1;
    }
    //printf("%d\n", fib(n));
    printf("%llu\n", fib_memoization(n, memory));
    return 0;
}