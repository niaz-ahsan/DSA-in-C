/*
Abstract Data Type using Array
*/

#include <stdio.h>
#include <stdlib.h>

struct ADT {
    int *ptr;
    int size; // total size of the array
    int length; // how many data already there
};

int append(struct ADT *, int); 
int display (struct ADT *);

int main(void) {
    // get total size from STDIN
    int size;
    printf("How long the array should be?: \n");
    scanf("%d", &size);
    
    // initiate ADT with size
    struct ADT arr;
    arr.size = size;
    arr.ptr = (int *) malloc (arr.size * sizeof(int));
    arr.length = 0;

    while (1) {
        int choice;
        printf("\n======================\n");
        printf("1. Display the array\n");
        printf("2. Append to the array\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display(&arr);
                break;
            case 2: 
                int data;
                printf("Int you want to append: \n");
                scanf("%d", &data);
                int status = append(&arr, data);
                (status < 0)? printf("Array is full!\n") : printf("Data appended successfully!\n");
                break;
            case 0:
                free(arr.ptr);
                exit(1);
            default:
                printf("Unrecognized input\n");
                break;   
        }
    }

    return 0;
}

int append(struct ADT * arr, int data) {
    // 0 = success, -1 = no space
    if (arr->size == arr->length) {
        return -1;
    }
    arr->ptr[arr->length] = data;
    arr->length++;
    return 0;
}

int display (struct ADT * arr) {
    for (int i=0; i<arr->size; i++) {
        printf("[%d]:%d ", i, arr->ptr[i]);
    }
    printf("\n");
}