/*
Contains all functions as solution of Hackerrank Tree related problems
*/

struct node {
    int data;
    struct node *left;
    struct node *right;
  
};

// Problem: Tree: Preorder Traversal
// link: https://www.hackerrank.com/challenges/tree-preorder-traversal/copy-from/338515740

void preOrder( struct node *root) {
    printf("%d ", root->data);
    if (root->left) {
        preOrder(root->left);
    }
    if (root->right) {
        preOrder(root->right);
    }
}