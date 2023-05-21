/*
Looking for 1+2+3+......+n = ?
Theoretically 1+2+3+....+(n-1)+n = (n * (n+1)) / 2
*/

#include <stdio.h>
#include <stdlib.h>

// recursive approach O(n)
int sum(int n) {
    if (n == 1) {
        return 1;
    } else if (n < 0) {
        return 0;
    }
    return n + sum(n-1);
}

//iterative approach O(n)
int iter_sum(int n) {
    int i;
    int sum = 0;
    for (i=1; i<=n; i++) {
        sum += i;
    }
    return sum;
}

// constant time O(1)
int sum_at_one_go(int n) {
    return (n * (n+1)) / 2;
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
    printf("[Recursion] Sum of 1+....+%d = %d\n", n, sum(n));
    printf("[Iteration] Sum of 1+....+%d = %d\n", n, iter_sum(n));
    printf("[Const. time] Sum of 1+....+%d = %d\n", n, sum_at_one_go(n));

    return 0;
}