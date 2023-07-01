#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Stack {
    int len;
    struct Node * top; // the left most Node (head), we'll expand on the left side.
    struct Node * start; // the right most Node (tail)
};

void push(int, struct Stack *);
int pop(struct Stack *);
void init_stack(struct Stack *);
void display(struct Stack *);
void free_st(struct Stack *);

int main(void) {
    struct Stack st;

    init_stack(&st);
    push(5, &st);
    push(4, &st);
    push(3, &st);
    display(&st);
    pop(&st);
    pop(&st);
    display(&st);
    pop(&st);
    display(&st);

    // at the end of operation
    free_st(&st);
}

void init_stack(struct Stack * st) {
    st->top = NULL;
    st->len = 0;
}

void push(int data, struct Stack * st) {
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    if (node == NULL) {
        // Heap memory is full
        printf("No space in Heap\n");
        return;
    }
    node->data = data;
    if (st->top == NULL) {
        // stack is empty
        node->next = NULL;
        st->start = node;
        st->top = node;
        st->len++;
        return;
    }
    // stack not empty
    node->next = st->top;
    st->top = node;
    st->len++;
}

int pop(struct Stack * st) {
    if (st->top == NULL) {
        printf("Stack empty!\n");
        return -1;
    }
    struct Node * current = st->top;
    st->top = st->top->next;
    int ret = current->data;
    free(current);
    st->len--;
    return ret;
}

void display(struct Stack * st) {
    printf("=================Display Stack===============\n");
    printf("Length: %d\n", st->len);
    struct Node * current = st->top;
    int i = 0;
    while (current != NULL) {
        printf("[%d]: %d\n", i, current->data);
        current = current->next;
        i++;
    }
    if (st->len) {
        printf("top poniter pointing at data: %d\n", st->top->data);
        printf("start pointer pointing at data: %d\n", st->start->data);
    }
    printf("================End Display=====================\n");
}

void free_st(struct Stack * st) {
    struct Node * current = st->top;
    while (current != NULL) {
        struct Node * temp = current->next;
        free(current);
        current = temp;
    }
}