// calloc() --> malloc() + data initialization to 0
// realloc() --> reallocates memory that were allocated earlier by malloc() / calloc()

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int * ptr;
    int bulk_size = 3;

    // allocating memory and setting value to 0
    ptr = (int *) calloc(bulk_size, sizeof(int));
    if (! ptr) {
        perror("Memory Allocation failed!\n");
    }
    int keep_going = 1;
    int data;
    int len = 0;
    int total_len = 0;
    while (keep_going) {
        if (len < bulk_size) {
            scanf("%d", &data);
            ptr[total_len] = data;
            total_len++;
            len++;
        } else {
            len = 0;
            printf("Wanna continue (1/0) ? : \n");
            scanf("%d", &keep_going);
            ptr = (int *) realloc(ptr, bulk_size * sizeof(int));
            if (! ptr) {
                perror("Memory Allocation failed\n");
                break;
            }
        }
    }
    printf("================================\n");
    printf("Total %d data stored!\n", total_len);
    for (int i=0; i<total_len; i++) {
        printf("[%d]: %d\n", i, ptr[i]);
    }

    return 0;
}