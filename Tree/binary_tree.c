#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char * data; // considering tree would have char
    struct Node * left_child;
    struct Node * right_child;
};

struct Q_node {
    struct Node * tree_node;
    int index; // for exploring the argv array, handling user input
    struct Q_node * next;
};

struct Q_return_node {
    struct Node * tree_node;
    int index;
};

struct Queue {
    int len;
    struct Q_node * first;
    struct Q_node * last;
};

struct Stack {
    struct Node ** stack;
    int end;
    int len;
};

void preorder_rec(struct Node *);
void preorder_it(struct Node *, int);
void inorder_rec(struct Node *);
void inorder_it(struct Node *, int);
void postorder_rec(struct Node *);
void postorder_it(struct Node *, int);
int count_nodes(struct Node *);
int count_height(struct Node *); 
int count_leaf_nodes(struct Node *);
void display_tree_postorder(struct Node *, int);
// ======= Stack related function definitions ========
void push(struct Stack * st, struct Node * node);
struct Node * pop(struct Stack * st);
// ======= Queue related function definitions ========
void init_queue(struct Queue * q);
void enqueue(struct Queue * q, struct Node * data, int index);
struct Q_return_node * dequeue(struct Queue * q); 
void display(struct Queue * q);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Syntax: <exe> <data separated by space level by level e.g. 5 4 3 100 null 2 1 101 102 null null>\n");
        exit(1);
    }
    struct Queue q;
    init_queue(&q);
    
    char * node_data = argv[1];
    if (strcmp(node_data, "null") == 0) {
        // null provided, code later
        printf("Root can't be NULL, fix it!\n");
        return 0;
    }
    // create the node in the memory
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    node->data = node_data;
    node->left_child = NULL;
    node->right_child = NULL;
    // enqueue the node
    enqueue(&q, node, 1);
    struct Node * root = node;
    //display(&q);
    while (q.len) {
        struct Q_return_node * p = dequeue(&q);
        int this_index = p->index;
        struct Node * node = p->tree_node;
        int left_child_index = this_index * 2;
        int right_child_index = (this_index * 2) + 1;
        if (left_child_index < argc) {
            // left child exists in the argv size
            if (strcmp(argv[left_child_index], "null") != 0) {
                // argv data isn't null
                struct Node * left_child_node = (struct Node *) malloc(sizeof(struct Node));
                left_child_node->data = argv[left_child_index];
                left_child_node->left_child = NULL;
                left_child_node->right_child = NULL;
                p->tree_node->left_child = left_child_node;
                enqueue(&q, left_child_node, left_child_index);
            }
        }
        //display(&q);
        if (right_child_index < argc) {
            // right child exists in the argv size
            if (strcmp(argv[right_child_index], "null") != 0) {
                // argv data isn't null
                struct Node * right_child_node = (struct Node *) malloc(sizeof(struct Node));
                right_child_node->data = argv[right_child_index];
                right_child_node->left_child = NULL;
                right_child_node->right_child = NULL;
                p->tree_node->right_child = right_child_node;
                enqueue(&q, right_child_node, right_child_index);
            }
        }
        //display(&q);
        //printf("================== DEBUG BEGIN ======================\n");
        //printf("Root: %s\n", p->tree_node->data);
        //printf("Left index: %d, Left data: %s\n", left_child_index-1, argv[left_child_index-1]);
        //printf("Right index: %d, Right data: %s\n", right_child_index-1, argv[right_child_index-1]);
        //printf("================== DEBUG END ======================\n");
    }
    
    printf("Preorder Traversal: ");
    preorder_rec(root);
    printf("\nInorder Traversal: ");
    inorder_rec(root);
    printf("\nPostorder Traversal: ");
    postorder_rec(root);
    printf("\n");
    printf("=============== Iterative approach begin ===============\n");
    printf("Preorder Traversal (iterative): ");
    preorder_it(root, argc - 1);
    printf("\n");
    printf("Inorder Traversal (Iterative): ");
    inorder_it(root, argc - 1);
    printf("\n");
    printf("Postorder Traversal (Iterative): ");
    postorder_it(root, argc - 1);
    printf("\n");
    printf("=============== Iterative approach end ===============\n");
    printf("Total Nodes: %d\n", count_nodes(root));
    printf("Tree Height: %d\n", count_height(root));
    printf("Total Leaf Nodes: %d\n", count_leaf_nodes(root));
    printf("=============== Attempting Tree Display ===============\n");
    display_tree_postorder(root, 1);
    return 0;
}

// Time O(n), Space O(h) - n = # of nodes, h = height of tree
void preorder_rec(struct Node * node) {
    printf(" %s ", node->data);
    if (node->left_child) {
        preorder_rec(node->left_child);
    }
    if (node->right_child) {
        preorder_rec(node->right_child);
    }
}

void preorder_it(struct Node * node, int size) {
    struct Stack st;
    st.end = -1;
    st.len = 0;
    st.stack = (struct Node **) malloc(size * sizeof(struct Node));
    while (node != NULL || st.len) {
        if (node != NULL) {
            printf(" %s ", node->data);
            push(&st, node); 
            node = node->left_child;
        } else {
            node = pop(&st);
            node = node->right_child;
        }
    }
}

// Time O(n), Space O(h) - n = # of nodes, h = height of tree
void inorder_rec(struct Node * node) {
    if (node->left_child) {
        inorder_rec(node->left_child);
    }
    printf(" %s ", node->data);
    if (node->right_child) {
        inorder_rec(node->right_child);
    }
}

void inorder_it(struct Node * node, int size) {
    struct Stack st;
    st.end = -1;
    st.stack = 0;
    st.stack = (struct Node **) malloc(size * sizeof(struct Node));
    while (node != NULL || st.len) {
        if (node != NULL) {
            push(&st, node); 
            node = node->left_child;
        } else {
            node = pop(&st);
            printf(" %s ", node->data);
            node = node->right_child;
        }
    }
}

// Time O(n), Space O(h) - n = # of nodes, h = height of tree
void postorder_rec(struct Node * node) {
    if (node->left_child) {
        postorder_rec(node->left_child);
    }
    if (node->right_child) {
        postorder_rec(node->right_child);
    }
    printf(" %s ", node->data);
}

void postorder_it(struct Node * root, int size) {
    // will be done later
}

int count_nodes(struct Node * node) {
    if (node == NULL) {
        return 0;
    }
    // formula: total nodes on left subtree + total nodes on right subtree + this node
    return count_nodes(node->left_child) + count_nodes(node->right_child) + 1;
}

int count_height(struct Node * node) {
    // height starts from 0 ...
    if (node == NULL) {
        return 0;
    }
    int x = 0, y = 0;
    x = count_height(node->left_child);
    y = count_height(node->right_child);
    if (x > y) {
        return x + 1;
    } else {
        return y + 1;
    }
}

int count_leaf_nodes(struct Node * node) {
    if (node == NULL)
        return 0;
    if (node->left_child == NULL && node->right_child == NULL)
        return 1;
    return count_leaf_nodes(node->left_child) + count_leaf_nodes(node->right_child);
}

void print_space_for_display(int count) {
    //printf("\n");
    for (int i=0; i<count; i++) {
        printf(" \t ");
    }
    printf("-----");
}

void display_tree_postorder(struct Node * node, int jumps) {
    if (node->right_child) 
        display_tree(node->right_child, jumps + 1);    
    print_space_for_display(jumps);    
    printf("%s\n", node->data);
    if (node->left_child) 
        display_tree(node->left_child, jumps + 1);
}

// ################### Stack related functions BEGIN ##########################

void push(struct Stack * st, struct Node * node) {
    st->end++;
    st->stack[st->end] = node;
    st->len++;
}

struct Node * pop(struct Stack * st) {
    struct Node * ret = st->stack[st->end];
    st->end--;
    st->len--;
    return ret;
}

// ################### Queue related functions BEGIN ##########################

void init_queue(struct Queue * q) {
    q->len = 0;
    q->first = NULL;
    q->last = NULL;
}

void enqueue(struct Queue * q, struct Node * data, int index) {
    struct Q_node * node = (struct Q_node *) malloc(sizeof(struct Q_node));
    if (node == NULL) {
        // Heap memory is full
        printf("No more space at Heap\n");
        return;
    } 
    node->tree_node = data;
    node->index = index;
    node->next = NULL;
    if(q->first == NULL) {
        // q is empty
        q->first = node;
        q->last = node;
    } else {
        // q not empty
        q->last->next = node;
        q->last = node;
    }
    q->len++;
}

struct Q_return_node * dequeue(struct Queue * q) {
    // -1 if q is empty, data otherwise
    if (q->first == NULL) {
        // q is empty
        printf("Queue is empty!\n");
        return NULL;
    }
    struct Node * tree_node = q->first->tree_node;
    struct Q_node * to_be_deleted = q->first;
    int index = to_be_deleted->index;
    q->first = q->first->next;
    free(to_be_deleted);
    q->len--;
    struct Q_return_node * ret = (struct Q_return_node *) malloc(sizeof(struct Q_return_node));
    ret->index = index;
    ret->tree_node = tree_node;
    return ret;
}

void display(struct Queue * q) {
    printf("=============== QUEUE DISPLAY START ===============\n");
    printf("Length: %d\n", q->len);
    struct Q_node * current = q->first;
    while(current != NULL) {
        printf("%s -->", current->tree_node->data);
        current = current->next;
    }
    printf("\n");
    if(q->len) {
        printf("[first] pointing at: %s\n", q->first->tree_node->data);
        printf("[last] pointing at: %s\n", q->last->tree_node->data);
    }
    printf("================ QUEUE DISPLAY END ================\n");
}

// ################### Queue related functions END ##########################