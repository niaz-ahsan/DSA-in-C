#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node * next;
};

struct Stack {
    int len;
    struct Node * top;
};

void init_stack(struct Stack *);
int push(struct Stack *, char);
char pop(struct Stack *);
void free_st(struct Stack *);

int main(int argc, char *argv[]) {
    if(argc <= 1) {
        printf("Syntax: <exe> <expression(s) separated by whitespace>\nexpression: {{a+b}*{c-d}}\n");
        return -1;
    } 
    

    for (int idx=1; idx<argc; idx++) {
        struct Stack st;
        char * exp = argv[idx];
        int i = 0;
        init_stack(&st);
        while (exp[i] != '\0') {
            if (exp[i] == '{') {
                int status = push(&st, '{');
                if (!status) {
                    printf("Program is terminating ...\n");
                    exit(1);
                } 
            } else if (exp[i] == '}') {
                char popped = pop(&st);
                if (popped == 'X') {
                    // error popping
                    printf("%s: Oops! Parentheses Mismatch!\n", exp);
                    exit(1);
                }
            }
            i++;
        }
        if(st.len == 0 && st.top == NULL) {
            printf("%s: Yay! Parentheses Match fine!\n", exp);
        } else {
            printf("%s: Oops! Parentheses Mismatch!\n", exp);
            free_st(&st);
        }
    }
    return 0;
}

void init_stack(struct Stack * st) {
    st->len = 0;
    st->top = NULL;
}

int push(struct Stack * st, char data) {
    /*
    1 --> on success
    -1 --> on failure
    */
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    if (node == NULL) {
        // no space on heap
        printf("Heap memory is full!\n");
        return -1;
    }
    node->data = data;
    if (st->top == NULL && st->len == 0) {
        // stack is empty
        node->next = NULL;
        st->top = node;
        st->len++;
        return 1;
    }
    // stack is not empty
    node->next = st->top;
    st->top = node;
    st->len++;
    return 1;
}

char pop(struct Stack * st) {
    /*
    '{' or '}' --> on success
    'X' --> on failure
    */
    if (st->top == NULL && st->len == 0) {
        // stack is empty
        return 'X';
    }
    // stack is not empty
    struct Node * node = st->top;
    st->top = node->next;
    char ret = node->data;
    free(node);
    st->len--;
    return ret;
}

void free_st(struct Stack * st) {
    struct Node * current = st->top;
    while(current != NULL) {
        struct Node * temp = current;
        current = current->next;
        free(temp);
    }
}