// Problem: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true


#include <stdio.h>
#include <stdlib.h>

void print_all_digits(int n) {
    if (n < 10) {
        printf("%d", n);
        return;
    }
    int quotient;
    do {
        quotient = n / 10;
        printf("%d", n % 10);
        n = quotient;
    } while (n >= 10);
    printf("%d", quotient);
} 

int find_digits(int num) {
    int total_divisor = 0;
    int quotient;
    int digit;
    int base = 10;
    int n = num;
    if (n < base) {
        return 1;
    }
    do {
        quotient = n / base;
        digit = n % base;
        if ((digit > 0) && (num % digit == 0)) 
            total_divisor++;
        n = quotient;
    } while (n >= base);
    if (num % quotient == 0)
            total_divisor++;
    return total_divisor;
}

int main() {
    int num = 1012;
    //print_all_digits(num);
    printf("%d\n", find_digits(num));
    return 0;
}