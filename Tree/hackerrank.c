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
    if (root->left) 
        preOrder(root->left);
    if (root->right) 
        preOrder(root->right);
}

// Problem: Tree: Postorder Traversal
// link: https://www.hackerrank.com/challenges/tree-postorder-traversal/copy-from/338516136

void postOrder( struct node *root) {
    if (root->left)
        postOrder(root->left);
    if (root->right)
        postOrder(root->right);
    printf("%d ", root->data);
}

// Problem: Tree: Inorder Traversal
// link: https://www.hackerrank.com/challenges/tree-inorder-traversal/copy-from/338516356

void inOrder( struct node *root) {
    if (root->left)
        inOrder(root->left);
    printf("%d ", root->data);    
    if (root->right)
        inOrder(root->right);
}