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
int display(struct ADT *);
int insert(struct ADT *, int, int);

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
        int choice, user_data, insert_index, status;
        printf("\n======================\n");
        printf("1. Display the array\n");
        printf("2. Append to the array\n");
        printf("3. Insert data at a given index\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display(&arr);
                break;
            case 2:
                printf("Int you want to append: \n");
                scanf("%d", &user_data);
                status = append(&arr, user_data);
                (status < 0)? printf("Array is full!\n") : printf("Data appended successfully!\n");
                break;
            case 3:
                printf("Int data & index: \n");
                scanf("%d%d", &user_data, &insert_index);
                status = insert(&arr, insert_index, user_data);
                (status < 0)? printf("Insert failed!\n") : printf("Data inserted successfully!\n");
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

int insert(struct ADT *arr, int index, int data) {
    // 0 = success, -1 = no space
    if (arr->size == arr->length || index < 0 || index > arr->size-1 ) {
        return -1;
    } else if (index > arr->length-1) {
        append(arr, data);
        arr->length++;
        return 0;
    }
    // shift all data to the right
    for (int i = arr->length-1; i>=index; i-- ) {
        arr->ptr[i+1] = arr->ptr[i];
    }
    arr->ptr[index] = data;
    arr->length++;
    return 0;
}