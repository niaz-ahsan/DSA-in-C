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