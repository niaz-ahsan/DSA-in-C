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
void init_stack(struct Stack *);
void push(struct Stack *, struct Node *);
struct Node * pop(struct Stack *);
// =========== Queue related functions ===========
void init_queue(struct Queue *);
void enqueue(struct Queue *, struct Node *);
struct Node * dequeue(struct Queue *);

int main(void) {
    return 0;
}