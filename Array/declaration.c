# include <stdio.h>

int main(void) {
    int a_size = 5, b_size = 5, c_size = 3;
    int a[5] = {2,3};
    int b[5] = {0};
    int c[] = {1,2,3};

    printf("a[5]: ");
    for (int i=0; i<a_size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("b[5]: ");
    for (int i=0; i<b_size; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");   

    printf("c[]: ");
    for (int i=0; i<c_size; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");   


    return 0;
}