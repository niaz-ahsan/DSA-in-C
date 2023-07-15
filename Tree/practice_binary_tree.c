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
void init_queue(struct Queue *, int);
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
    if (st->end < 0) {
        // if empty return NULL
        return NULL;
    }
    struct Node * removed_node = st->data[st->end];
    st->end--;
    st->len--;
    return removed_node;
}

// ################### Stack related functions END ##########################

// ################### Queue related functions BEGIN ##########################

void init_queue(struct Queue * q, int size) {
    q->push_stack->data = (struct Node **) malloc(size * sizeof(struct Node));
    q->push_stack->end = -1;
    q->push_stack->len = 0;

    q->pop_stack->data = (struct Node **) malloc(size * sizeof(struct Node));
    q->pop_stack->end = -1;
    q->pop_stack->len = 0;
}

void enqueue(struct Queue * q, struct Node * node) {
    // add it later
}

struct Node * dequeue(struct Queue * q) {
    if (q->pop_stack->end < 0) {
        return NULL;
    }
    struct Node * removed_node = q->pop_stack->data[q->pop_stack->end];
    q->pop_stack->end--;
    q->pop_stack->len--;
    return removed_node;
}
// ################### Queue related functions END ##########################