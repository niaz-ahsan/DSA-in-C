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

struct Queue {
    struct Queue_node * head;
    struct Queue_node * tail;
    int len;
};

struct Queue_node {
    struct Node * node;
    struct Queue_node * next;
};


void display(struct Node *, int);
void preorder_traversal(struct Node * node);
void inorder_traversal(struct Node * node);
void level_order_traversal(struct Node * node);
// ========= Stack functions =========
void init_stack(struct Stack * st);
void push(struct Stack * st, struct Node * node, int level);
struct Stack_node * pop(struct Stack * st);
void display_stack(struct Stack * st);
// ======== Queue functions ==========
void init_queue(struct Queue * q);
void enqueue(struct Queue * q, struct Node * node);
struct Node * dequeue(struct Queue * q);


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
    third.right = &seventh;

    display(&root, 1);
    preorder_traversal(&root);
    //inorder_traversal(&root);
    level_order_traversal(&root);
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
    printf("========== Preorder Traversal Top view ===========\n");
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

int is_top_level_node_inorder(int level, int * right_max) {
    if ( (level != 0) & (level > *(right_max)) ) {
        *(right_max) = level;
        return 1;
    }
    return 0;
}

void inorder_traversal(struct Node * node) {
    printf("========== Inorder Traversal Top view ===========\n");
    struct Node * root = node;
    struct Stack st;
    init_stack(&st);
    int level = 0;
    int right_max = -501;
    int has_zero_visited = 0;
    while (node || st.len) {
        if (node) {
            push(&st, node, level);
            node = node->left;
            level = level - 1;
        } else {
            struct Stack_node * st_node = pop(&st);
            node = st_node->node;
            //printf("data %d | level %d\n", node->data, st_node->level);
            if(node == root) {
                printf("%d | level %d\n", node->data, st_node->level);
            } else if (is_top_level_node_inorder(st_node->level, &right_max)) {
                printf("%d | level %d\n", node->data, st_node->level);
            }
            level = st_node->level + 1;
            node = node->right;
        }
    }
}

void level_order_traversal(struct Node * node) {
    printf("======= Level Order =======\n");
    struct Queue q;
    init_queue(&q);
    enqueue(&q, node);
    while (q.len) {
        struct Node * this_node = dequeue(&q);
        printf("%d ", this_node->data);
        if (this_node->left) {
            enqueue(&q, this_node->left);
        }
        if (this_node->right) {
            enqueue(&q, this_node->right);
        }
    }
    printf("\n");
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

// ============= Queue implementation ==============
void init_queue(struct Queue * q) {
    q->head = NULL;
    q->tail = NULL;
    q->len = 0;
}

void enqueue(struct Queue * q, struct Node * node) {
    // creating the node
    struct Queue_node * q_node = (struct Queue_node *) malloc(sizeof(struct Queue_node));
    q_node->node = node;
    q_node->next = NULL;
    if (q->head) {
        // q not empty, append the new node
        q->tail->next = q_node;
        q->tail = q_node;
        q->len++;
        return;
    }
    // q is empty
    q->head = q_node;
    q->tail = q_node;
    q->len++;
}

struct Node * dequeue(struct Queue * q) {
    if (q->head) {
        // q not empty, dequeue the head
        struct Queue_node * to_be_deleted = q->head;
        q->head = q->head->next;
        q->len--;
        struct Node * ret = to_be_deleted->node;
        free(to_be_deleted);
        return ret;
    }
    // q empty
    return NULL;
}
