/*
Looking for 1+2+3+......+n = ?
*/

#include <stdio.h>
#include <stdlib.h>

int sum(int n) {
    if (n == 1) {
        return 1;
    } else if (n < 0) {
        return 0;
    }
    return n + sum(n-1);
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
    printf("Sum of 1+....+%d = %d\n", n, sum(n));
    return 0;
}