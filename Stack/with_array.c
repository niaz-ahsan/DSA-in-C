#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size; // size of the stack
    int top; // initially -1, with new data insert it will be 1,2,3... data will always be pulled from top position
    int *start; // a stack that will hold int, pointer pointing at the 1st elem
};

void init_stack(struct stack *);
void push(int, struct stack *);
void display(struct stack *);
int pop(struct stack *);
int peek(struct stack *, int);

int main(void) {
    struct stack st;
    printf("Enter size:\n");
    scanf("%d", &st.size);
    printf("\n");

    init_stack(&st);
    push(5, &st);
    push(3, &st);
    push(2, &st);
    push(1, &st);
    display(&st);
    printf("Peeking at pos 3: %d\n", peek(&st, 3));
    printf("Peeking at pos 1: %d\n", peek(&st, 1));
    printf("Peeking at pos 6: %d\n", peek(&st, 6));
    pop(&st);
    pop(&st);
    display(&st);

    //end of operation
    free(st.start);
}

void init_stack(struct stack *st) {
    st->start = (int *) malloc(st->size * sizeof(int));
    st->top = -1;
}

void push(int data, struct stack * st) {
    if (st->top == st->size - 1) {
        // stack is full
        printf("Stack is full! Push failed!\n");
        return;
    }
    st->top++;
    st->start[st->top] = data;
}

int pop(struct stack *st) {
    int ret = -1;
    if(st->top == -1) {
        // stack empty
        printf("Stack is empty. Pop failed\n");
        return ret;
    }
    ret = st->start[st->top];
    st->top--;
    return ret;
}

int peek(struct stack *st, int pos) {
    /*
    pos 1 --> top elem
    pos 2 --> 2nd top elem
    ...
    */
    if (pos > st->top + 1 || pos < 1) {
        printf("Invalid index provided\n");
        return -1;
    }
    return st->start[st->top + 1 - pos];
}

void display(struct stack *st) {
    printf("=================Displaying Stack===============\n");
    printf("Size: %d\n", st->size);
    for (int i=st->top; i>=0; i--) {
        printf("[%d]: %d\n", i, st->start[i]);
    }
    printf("top pointing at: %d\n", st->top);
    printf("================End Display=====================\n");
}