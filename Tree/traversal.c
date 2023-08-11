#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

void display(struct Node *, int);

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