#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Stack {
    int size;
    struct Node * top; // the left most Node (head), we'll expand on the left side.
    struct Node * start; // the right most Node (tail)
};

void push(int, struct Stack *);
void init_stack(struct Stack *);
void display(struct Stack *);
void free_st(struct Stack *);

int main(void) {
    struct Stack st;
    printf("Provide size: \n");
    scanf("%d", &st.size);

    init_stack(&st);
    push(5, &st);
    push(4, &st);
    push(3, &st);
    display(&st);

    // at the end of operation
    free_st(&st);
}

void init_stack(struct Stack * st) {
    st->top = NULL;
}

void push(int data, struct Stack * st) {
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    if (st->top == NULL) {
        // stack is empty
        node->next = NULL;
        st->start = node;
        st->top = node;
        return;
    }
    // stack not empty
    node->next = st->top;
    st->top = node;
}

void display(struct Stack * st) {
    printf("=================Displaying Stack===============\n");
    printf("Size: %d\n", st->size);
    struct Node * current = st->top;
    int i = 0;
    while (current != NULL) {
        printf("[%d]: %d\n", i, current->data);
        current = current->next;
        i++;
    }
    printf("top poniter pointing at data: %d\n", st->top->data);
    printf("start pointer pointing at data: %d\n", st->start->data);
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