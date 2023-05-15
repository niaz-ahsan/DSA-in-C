#include <stdio.h>

int rec(int a) {
    static int x = 0;
    if (a > 0) {
        x++;
        return (rec(a-1) + x);
    }
    return 0;
}

int main(void) {
    int n;
    printf("Provide integer input:\n");
    scanf("%d", &n);
    printf("%d\n", rec(n));
    return 0;
}