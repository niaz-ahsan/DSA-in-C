#include <stdio.h>

void funcB(int a) {
    if (a > 0) {
        printf("B: %d\n", a);
        funcA(a / 2);
    }
}

void funcA(int a) {
    if (a > 0) {
        printf("A: %d\n", a);
        funcB(a - 1);
    }
}

int main(void) {
    int n;
    printf("Provide int:\n");
    scanf("%d", &n);
    funcA(n);
    return 0;
}