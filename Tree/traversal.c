#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Stack_node {
    struct Node * node;
    int level;
    struct Stack_node * next;
};

struct Stack {
    int len;
    struct Stack_node * head; // stack increases at the left, push at head and pop at head
};


void display(struct Node *, int);
void preorder_traversal(struct Node * node);
// ========= Stack functions =========
void init_stack(struct Stack * st);
void push(struct Stack * st, struct Node * node, int level);
struct Stack_node * pop(struct Stack * st);
void display_stack(struct Stack * st);



int main(void) {
    struct Node root = {1, NULL, NULL};
    struct Node second = {2, NULL, NULL};
    struct Node third = {3, NULL, NULL};
    struct Node fourth = {4, NULL, NULL};
    struct Node fifth = {5, NULL, NULL};
    struct Node sixth = {6, NULL, NULL};
    struct Node seventh = {7, NULL, NULL};

    root.left = &second;
    root.right = &third;
    second.left = &fourth;
    second.right = &fifth;
    third.left = &sixth;
    //third.right = &seventh;

    display(&root, 1);
    preorder_traversal(&root);
    return 0;
}

void print_space(int jumps) {
    for (int i=0; i<jumps; i++) {
        printf("\t");
    }
}

void display(struct Node * node, int jumps) {
    if (node) {
        display(node->right, jumps + 1);
        print_space(jumps);
        printf("%d\n", node->data);
        display(node->left, jumps + 1);
    }
}

int is_top_level_node(int level, int * left_min, int * right_max, int * has_zero_visited) {
    if (level < 0) {
        if (level < *(left_min)) {
            *(left_min) = level;
            return 1;
        } 
    } else if (level > 0) {
        if (level > *(right_max)) {
            *(right_max) = level;
            return 1;
        }
    } else {
        if (! *(has_zero_visited)) {
            *(has_zero_visited) = 1;
            return 1;
        }
    }
    return 0;
}

void preorder_traversal(struct Node * node) {
    struct Stack st;
    init_stack(&st);
    int level = 0;
    int left_min = 0;
    int right_max = 0;
    int has_zero_visited = 0;
    while (node || st.len) {
        if (node) {
            //printf("data %d | level %d\n", node->data, level);
            if (is_top_level_node(level, &left_min, &right_max, &has_zero_visited)) {
                printf("%d | level %d\n", node->data, level);
            }
            push(&st, node, level);
            node = node->left;
            level = level - 1;
        } else {
            struct Stack_node * st_node = pop(&st);
            node = st_node->node;
            level = st_node->level + 1;
            node = node->right;
        }
    }
}

// ============= Stack implementation ==============
void init_stack(struct Stack * st) {
    st->head = NULL;
    st->len = 0;
}

void push(struct Stack * st, struct Node * node, int level) {
    // generating stack node
    struct Stack_node * st_node = (struct Stack_node *) malloc(sizeof(struct Stack_node));
    st_node->node = node;
    st_node->level = level;
    st_node->next = NULL;
    // add it to stack's left
    if (st->head) {
        // stack not empty
        st_node->next = st->head;
        st->head = st_node;
    } else {
        // stack empty
        st->head = st_node;
    }
    st->len++;
}

struct Stack_node * pop(struct Stack * st) {
    if (! st->head) {
        return NULL;
    }
    struct Stack_node * temp = st->head;
    st->head = st->head->next;
    st->len--;
    return temp;
}

void display_stack(struct Stack * st) {
    struct Stack_node * curr = st->head;
    while (curr) {
        printf("data = %d | level = %d\n", curr->node->data, curr->level);
        curr = curr->next;
    }
}