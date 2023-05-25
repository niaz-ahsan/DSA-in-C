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

// iterative approach
void iter_fib(int * series, int n) {
    series[0] = 0;
    series[1] = 1;
    int i;
    for (i=2; i<=n; i++) {
        series[i] = series[i-1] + series[i-2];
    }
}

void print_array(int * a, int size) {
    int i;
    for (i=0; i<=size; i++) {
        printf("[%d]: %d \n", i, a[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Syntax: <exe> <nth term>\n");
        exit(1);
    }
    int n = atoi(argv[1]); // converting param to int which is the n
    if (n < 0) {
        printf("Provide +ve index\n");
        exit(1);
    }
    
    // execute normal recursive fibonacci
    printf("Executing Recursive implementation\n");
    printf("==================================\n");
    printf("%d\n", fib(n));
    
    // execute recursive memoization fibonacci upto 93rd digit
    printf("Executing Recursive implementation with Memoization\n");
    printf("===================================================\n");
    unsigned long long memory[n];
    int i;
    for (i=0; i<=n; i++) {
        memory[i] = -1;
    }
    printf("%llu\n", fib_memoization(n, memory));
    
    //execute fibonacci via iterative approach
    printf("Executing Iterative implementation\n");
    printf("==================================\n");
    int p[n];
    iter_fib(p, n);
    print_array(p, n);
    return 0;
}