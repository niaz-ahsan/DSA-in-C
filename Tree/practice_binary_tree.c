#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char * data;
    int index; // only required to generate tree from array, otherwise redundant.
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

struct Node * generate_tree(char ** data, int);
void display_tree(struct Node *, int);
// =========== Stack related functions ===========
void init_stack(struct Stack *, int);
void push(struct Stack *, struct Node *);
struct Node * pop(struct Stack *);
// =========== Queue related functions ===========
void init_queue(struct Queue *, int);
void enqueue(struct Queue *, struct Node *);
struct Node * dequeue(struct Queue *);
int queue_is_empty(struct Queue *);

int main(void) {    
    char * tree_data[] = {"1","2","3","4","5","-1","-1"}; // -1 = NULL
    int len = 7;
    struct Node * root = generate_tree(tree_data, len);
    display_tree(root, 1);
    return 0;
}

struct Node * create_node(char * data, int index) {
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->index = index;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node * generate_tree(char ** data, int size) {
    // Queue initialization
    struct Stack push_st, pop_st;
    struct Queue q;
    q.push_stack = &push_st;
    q.pop_stack = &pop_st;
    init_queue(&q, size);
    // root node setup
    struct Node * root;
    if (size <= 0) {
        printf("Tree data not provided!\n");
        return NULL;
    }
    root = create_node(data[0], 0);
    enqueue(&q, root);
    // generation of rest of the tree
    while (! queue_is_empty(&q) ) {
        struct Node * node = dequeue(&q);
        if (! node) {
            // redunddant block
            printf("Tree generation Queue is empty\n");
            return NULL;    
        }
        int left_index = ((node->index + 1) * 2) - 1; // left child 2i, when i starts from 1
        int right_index = ((node->index + 1) * 2); // right child 2i+1, when i starts from 1
        if (left_index < size && strcmp(data[left_index], "-1") != 0 ) {
            // index exists in tree array && data isn't -1
            struct Node * left_node = create_node(data[left_index], left_index);
            node->left = left_node;
            enqueue(&q, left_node);
        }
        if (right_index < size && strcmp(data[right_index], "-1") != 0 ) {
            // index exists in tree array && data isn't -1
            struct Node * right_node = create_node(data[right_index], right_index);
            node->right = right_node;
            enqueue(&q, right_node);
        }
    }
    return root;
}

void print_space_for_display(int count) {
    //printf("\n");
    for (int i=0; i<count; i++) {
        printf(" \t ");
    }
}

void display_tree(struct Node * node, int jumps) {
    if (node->right) 
        display_tree(node->right, jumps + 1);    
    print_space_for_display(jumps);    
    printf("%s\n", node->data);
    if (node->left) 
        display_tree(node->left, jumps + 1);
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

int queue_is_empty(struct Queue * q) {
    if (q->push_stack->len <= 0 && q->pop_stack->len <= 0) 
        return 1;
    else 
        return 0;
}

// ################### Queue related functions END ##########################