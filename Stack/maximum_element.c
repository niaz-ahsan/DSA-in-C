// Problem link: https://www.hackerrank.com/challenges/maximum-element/problem?isFullScreen=true 
/*
Stack created using an elastic array.
*/

#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 3

int * init_stack(int *); 
void push(int *, int, int *);
int pop(int *, int *);
void display (int * , int *);

int main(void) {
    int * ptr;
    int index = -1;
    ptr = init_stack(ptr);
    push(ptr, 15, &index);
    push(ptr, 20, &index);
    push(ptr, 19, &index);
    push(ptr, 100, &index);
    push(ptr, 400, &index);
    push(ptr, 300, &index);
    push(ptr, 950, &index);
    push(ptr, 890, &index);
    display(ptr, &index);
    pop(ptr, &index);
    display(ptr, &index);
}

int * init_stack(int * p) {
    p = (int *) calloc(MIN_SIZE, sizeof(int));
    if (! p) {
        perror("Memory Allocation Failed!\n");
    } 
    return p;
}

void push(int * p, int data, int * index) {
    if ( (*index + 1 >= MIN_SIZE) && ((*index + 1) % MIN_SIZE == 0) ) {
        // need reallocation of memory and push
        p = (int *) realloc(p, MIN_SIZE * sizeof(int));
    } 
    *index = *index + 1;
    p[*index] = data;
}

int pop(int * p, int * index) {
    if (*index < 0) {
        // no data to pop
        return -420;
    }
    int output = p[*index];
    p[*index] = 0;
    *index = *index - 1;
    return output;
}

void display (int * p, int * index) {
    printf("======= Stack display ==========\n");
    for (int i=0; i<=*index; i++) {
        printf("[%d]: %d\n", i, p[i]);
    }
}