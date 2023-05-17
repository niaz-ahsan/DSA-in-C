#include <stdio.h>

// Tree Rec
void func(int a) {
    if (a > 0) {
        printf("%d ", a);
        func(a-1);
        func(a-1);
    }
}

int main() {
    int n;
    printf("Provide integer:\n");
    scanf("%d", &n);
    func(n);
    printf("\n");
    return 0;
}