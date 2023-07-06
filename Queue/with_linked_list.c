#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Queue {
    int len;
    struct Node * first;
    struct Node * last;
};

int main(void) {
    
}