#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * create_node(int);
void display_tree(struct Node *, int);
void inorder_traversal(struct Node *);
int search(struct Node *, int, int);
void print_search_result(int, int);
void iter_search(struct Node *, int);

int main(void) {
    struct Node * root = create_node(8);
    root->left = create_node(3);
    root->left->left = create_node(1);
    root->left->right = create_node(6);
    root->left->right->left = create_node(4);
    root->left->right->right = create_node(7);
    root->right = create_node(10);
    root->right->right = create_node(14);
    root->right->right->left = create_node(13);
    
    display_tree(root, 1);
    printf("\nData is sorted as follows: ");
    inorder_traversal(root);
    printf("\n=============== Recursive Seacrh ==============\n");
    int s_4 = search(root, 4, 0);
    print_search_result(4, s_4);
    int s_14 = search(root, 14, 0);
    print_search_result(14, s_14);
    int s_12 = search(root, 12, 0);
    print_search_result(12, s_12);
    printf("\n=============== Iterative Seacrh ==============\n");
    iter_search(root, 4);
    iter_search(root, 14);
    iter_search(root, 12);
    return 0;
}

struct Node * create_node(int data) {
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void print_space_for_display(int count) {
    for (int i=0; i<count; i++) {
        printf(" \t ");
    }
}

void display_tree(struct Node * node, int jumps) {
    if (node->right) 
        display_tree(node->right, jumps + 1);    
    print_space_for_display(jumps);    
    printf("%d\n", node->data);
    if (node->left) 
        display_tree(node->left, jumps + 1);
}

void inorder_traversal(struct Node * node) {
    if (node) {
        inorder_traversal(node->left);
        printf(" %d ", node->data);
        inorder_traversal(node->right);
    }
}

// time O(h), h = height of tree = logn
int search(struct Node * node, int data, int jumps) {
    // +ve int --> if data found, -1 --> if data not found
    if(! node) 
        return -1;
    if (data < node->data) 
        return search(node->left, data, ++jumps);
    else if (data > node->data) 
        return search(node->right, data, ++jumps);
    else
        return jumps; // data == node->data, found!

}

void print_search_result(int data, int output) {
    (output > -1)? printf("%d is found, hops needed: %d\n", data, output) : printf("%d NOT found!\n", data);
}

void iter_search(struct Node * node, int data) {
    int hops = 0;
    while (node && node->data != data) {
        //printf("%d\n", node->data);
        if (data < node->data) {
            node = node->left;
        }
        else if (data > node->data) {
            node = node->right;
        }
        hops++;
    }
    if(node) {
        printf("%d is found, hops needed: %d\n", data, hops);
    } else {
        printf("%d NOT found\n", data);
    }
}