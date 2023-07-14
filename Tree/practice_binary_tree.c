#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char * data;
    struct Node * left;
    struct Node * right;
};

struct Stack {
    struct Node ** data;
    int len;
    int end;
};

struct Queue {
    // implementing Queue using two stacks
    struct Stack * push_stack;
    struct Stack * pop_stack;
};

// =========== Stack related functions ===========
void init_stack(struct Stack *, int);
void push(struct Stack *, struct Node *);
struct Node * pop(struct Stack *);
// =========== Queue related functions ===========
void init_queue(struct Queue *);
void enqueue(struct Queue *, struct Node *);
struct Node * dequeue(struct Queue *);

int main(void) {
    return 0;
}

// ################### Stack related functions BEGIN ##########################

void init_stack(struct Stack * st, int size) {
    st->data = (struct Node **) malloc(size * sizeof(struct Node));
    st->len = 0;
    st->end = -1;
}

void push(struct Stack * st, struct Node * node) {
    st->end++;
    st->data[st->end] = node;
    st->len++;
}

struct Node * pop(struct Stack * st) {
    struct Node * removed_node = st->data[st->end];
    st->end--;
    st->len--;
    return removed_node;
}

// ################### Stack related functions END ##########################

// ################### Queue related functions BEGIN ##########################



// ################### Queue related functions END ##########################