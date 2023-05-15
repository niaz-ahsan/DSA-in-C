/*
Based on user input integer n
n n-1 n-2 ..... 1 
1 2 3 ..... n-1 n 
will be printed recursively
*/

#include <stdio.h>

void desc_rec(int a) {
    if (a > 0) {
        printf("%d ", a);
        desc_rec(a-1);
    }
}

void asc_rec(int a) {
    if (a > 0) {
        asc_rec(a-1);
        printf("%d ", a);
    }
}

int main() {
    int n;
    printf("Provide input:\n");
    scanf("%d", &n);
    asc_rec(n);
    printf("\n");
    desc_rec(n);
    printf("\n");
    return 0;
}