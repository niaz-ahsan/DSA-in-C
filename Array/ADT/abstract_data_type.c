/*
Abstract Data Type using Array
*/

#include <stdio.h>
#include <stdlib.h>
#include "./quicksort.h"
#include "./binary_search.h"

struct ADT {
    int *ptr; // points at array of int data
    int size; // total size of the array
    int length; // how many data already there
};

int append(struct ADT *, int); 
int display(struct ADT *);
int insert(struct ADT *, int, int);
void length_size(struct ADT *);
int delete(struct ADT *, int);
int linear_search(struct ADT *, int);
void reverse(struct ADT *);

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
        char to_continue;
        printf("\n======================\n");
        printf("1. Display the array\n");
        printf("2. Append to the array\n");
        printf("3. Insert data at a given index\n");
        printf("4. Delete data at a given index\n");
        printf("5. Sort the data\n");
        printf("6. Search a data (Linear)\n");
        printf("7. Search a data (Binary Iterative)\n");
        printf("8. Search a data (Binary Recursive)\n");
        printf("9. View Size n Length\n");
        printf("10. Reverse the whole thing\n");
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
            case 4:
                printf("Int index from where you wanna delete data: \n");
                scanf("%d", &insert_index);
                status = delete(&arr, insert_index);
                (status < 0)? printf("Deletion failed!\n") : printf("Data deleted successfully!\n");
                break;  
            case 5:
                quicksort(arr.ptr, 0, arr.length-1); 
                break;
            case 6:
                printf("Which int are you looking for? \n");
                scanf("%d", &user_data);
                status = linear_search(&arr, user_data);
                (status < 0)? printf("[%d] Not Found!\n", user_data) : printf("[%d] Found @ Index: [%d]\n", user_data, status);
                break;     
            case 7:
                printf("This will sort the data from smallest to largest (Ascending order)\n");
                printf("Which int are you looking for?\n");
                scanf("%d", &user_data);
                quicksort(arr.ptr, 0, arr.length-1);
                status = search(arr.ptr, 0, arr.length-1, user_data);
                (status < 0)? printf("[%d] Not Found!\n", user_data) : printf("[%d] Found @ Index: [%d]\n", user_data, status);
                break; 
            case 8:
                printf("This will sort the data from smallest to largest (Ascending order)\n");
                printf("Which int are you looking for?\n");
                scanf("%d", &user_data);
                quicksort(arr.ptr, 0, arr.length-1);
                status = rec_search(arr.ptr, 0, arr.length-1, user_data);
                (status < 0)? printf("[%d] Not Found!\n", user_data) : printf("[%d] Found @ Index: [%d]\n", user_data, status);
                break;     
            case 9:
                length_size(&arr);
                break;
            case 10:
                reverse(&arr);
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

// Time O(1)
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

// Time O(n)
int insert(struct ADT *arr, int index, int data) {
    // 0 = success, -1 = no space
    if (arr->size == arr->length || index < 0 || index > arr->size-1 ) {
        return -1;
    } else if (index > arr->length-1) {
        append(arr, data);
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

void length_size(struct ADT *arr) {
    printf("Size: %d\nLength: %d\n", arr->size, arr->length);
}

int is_valid_index(struct ADT *arr, int index) {
    // 0 -> valid, -1 -> invalid
    if (index >= 0 && index <= arr->size-1) {
        return 0;
    } 
    return -1;
}

int is_valid_index_within_data_limit(struct ADT *arr, int index) {
    // 0 -> valid, -1 -> invalid
    if (index >= 0 && index <= arr->length-1) {
        return 0;
    } 
    return -1;
}

// Time O(n)
int delete(struct ADT *arr, int index) {
    // 0 -> success, -1 -> error
    if (is_valid_index_within_data_limit(arr, index) < 0) {
        return -1;
    }
    for (int i=index; i<=arr->length-1; i++) {
        arr->ptr[i] = arr->ptr[i+1];
    }
    arr->ptr[arr->length-1] = 0;
    arr->length--;
    return 0;
}

// Time O(n)
int linear_search(struct ADT *arr, int data) {
    // int index -> success, -1 -> error
    for (int i=0; i<arr->length; i++) {
        if(arr->ptr[i] == data) {
            return i;
        }
    }
    return -1;
}

void reverse(struct ADT * arr) {
    int low = 0;
    int high = arr->length-1;
    while (low < high) {
        int temp = arr->ptr[low];
        arr->ptr[low] = arr->ptr[high];
        arr->ptr[high] = temp;
        low++;
        high--;
    }
}

