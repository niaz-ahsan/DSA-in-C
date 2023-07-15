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
    struct Stack push_st, pop_st;
    struct Queue q;
    q.push_stack = &push_st;
    q.pop_stack = &pop_st;
    init_queue(&q, 7);
    
    
    struct Node niaz = {"Niaz", NULL, NULL};
    struct Node ahsan = {"Ahsan", NULL, NULL};
    struct Node prodhan = {"Prodhan", NULL, NULL};
    struct Node zuni = {"Zunaira", NULL, NULL};
    struct Node zainab = {"Zainab", NULL, NULL};
    struct Node sidd = {"Siddiqua", NULL, NULL};
    struct Node x = {"X", NULL, NULL};
    
    enqueue(&q, &niaz);
    enqueue(&q, &ahsan);
    enqueue(&q, &prodhan);
    struct Node * removed = dequeue(&q);
    printf("Popped: %s\n", removed->data);
    enqueue(&q, &zuni);
    enqueue(&q, &zainab);
    struct Node * removed_again = dequeue(&q);
    printf("Popped: %s\n", removed_again->data);

    struct Node * removed_again2 = dequeue(&q);
    printf("Popped: %s\n", removed_again2->data);

    struct Node * removed_again3 = dequeue(&q);
    printf("Popped: %s\n", removed_again3->data);

    struct Node * removed_again4 = dequeue(&q);
    printf("Popped: %s\n", removed_again4->data);

    struct Node * removed_again5 = dequeue(&q);
    printf("Popped: %p\n", removed_again5);

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
    init_stack(q->push_stack, size);
    init_stack(q->pop_stack, size);
}

void enqueue(struct Queue * q, struct Node * node) {
    // just push in push_stack
    push(q->push_stack, node);
}

int stack_to_stack_transfer(struct Stack * src, struct Stack * des) {
    // 0 --> No transfer took place, (+)ve --> transfer took place
    int total_transfer = 0;
    while (src->len > 0) {
        struct Node * popped_node = pop(src);
        push(des, popped_node);
        total_transfer++;
    }
    return total_transfer;
}

struct Node * dequeue(struct Queue * q) {
    /*
    pop from pop_stack.
    if pop_stack is empty, pop all elements from push_stack.
    if push_stack is also empty, queue is empty
    */ 
    if (q->pop_stack->end < 0) {
        // pop_stack is empty, transfer
        int success = stack_to_stack_transfer(q->push_stack, q->pop_stack);
        if (! success) {
            printf("Queue is empty!");
            return NULL;
        }
    }
    struct Node * removed_node = pop(q->pop_stack);
    return removed_node;
}
// ################### Queue related functions END ##########################