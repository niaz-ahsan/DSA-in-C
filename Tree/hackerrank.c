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

// Problem: Tree: Height of a Binary Tree
// link: https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/copy-from/338517538

int getHeight(struct node* root) {
    // Write your code here
    if (!root)
        return -1;
    int x = getHeight(root->left);
    int y = getHeight(root->right);
    if (x > y) 
        return x + 1;
    else 
        return y + 1;
}

// Problem: Tree: Level Order Traversal
// link: https://www.hackerrank.com/challenges/tree-level-order-traversal/submissions/code/341136175

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

// Problem: Binary Search Tree : Insertion
// link: https://www.hackerrank.com/challenges/binary-search-tree-insertion/submissions/code/341241968

struct node* insert( struct node* root, int data ) {
	struct node * node = (struct node *) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    struct node * prev = NULL;
    struct node * curr = root;
    if (!curr) {
        return node;
    }
    while (curr) {
        prev = curr;
        if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if (data < prev->data) {
        prev->left = node;
    } else if (data > prev->data) {
        prev->right = node;
    }
    return root;
}