#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Parent_child_node {
    struct Node * parent;
    struct Node * child;
};

struct Node * create_node(int);
void display_tree(struct Node *, int);
void inorder_traversal(struct Node *);
int search(struct Node *, int, int);
void print_search_result(int, int);
void iter_search(struct Node *, int);
struct Node * insert_new_node(struct Node *, int);
struct Parent_child_node inorder_predecessor(struct Node *);
struct Parent_child_node inorder_successor(struct Node *);
struct Parent_child_node search_node_and_parent(struct Node *, int);
int height(struct Node *);
int is_leaf(struct Node *);
struct Node * delete(struct Node *, int);

int main(void) {
    struct Node * root = insert_new_node(NULL, 8);
    struct Node * n_3 = insert_new_node(root, 3);
    struct Node * n_1 = insert_new_node(root, 1);
    struct Node * n_6 = insert_new_node(root, 6);
    struct Node * n_4 = insert_new_node(root, 4);
    struct Node * n_7 = insert_new_node(root, 7);
    struct Node * n_10 = insert_new_node(root, 10);
    struct Node * n_14 = insert_new_node(root, 14);
    struct Node * n_13 = insert_new_node(root, 13);
    struct Node * n_18 = insert_new_node(root, 18);
    struct Node * n_9 = insert_new_node(root, 9);
    struct Node * n_2 = insert_new_node(root, 2);
    struct Node * n_100 = insert_new_node(root, 100);

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
    printf("\n");
    /*struct Parent_child_node in_pre = inorder_predecessor(root);
    struct Parent_child_node in_suc = inorder_successor(root);
    printf("Inorder pred of root: %d %d\n", in_pre.parent->data, in_pre.child->data);
    printf("Inorder succ of root: %d %d\n", in_suc.parent->data, in_suc.child->data);
    printf("Height of the tree: %d\n", height(root));
    struct Parent_child_node searched = search_node_and_parent(root, 13);
    printf("Search of 13: %d %d\n", searched.parent->data, searched.child->data);*/
    printf("Deleting 8\n");
    delete(root, 8);
    display_tree(root, 1);
    printf("\n");
    inorder_traversal(root);
    printf("\n");
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

struct Node * insert_new_node(struct Node * node, int data) {
    /*
    first search the exact position, if the same data is found dont duplicate.
    Use trailing pointer to have the last node visited in order to insert the node once 
    proper place for the node is found.
    */ 
    struct Node * trailing = NULL;
    struct Node * new_node = create_node(data);
    while (node && node->data != data) {
        trailing = node;
        if (data < node->data) {
            node = node->left;
        } else if (data > node->data) {
            node = node->right;
        }
    }
    if (node) {
        // that data already exists. Dont insert.
        printf("Data already exists. Insert not needed\n");
        return NULL;
    }
    // node is NULL, so insert required.
    if (trailing) {
        if (data < trailing->data) 
            trailing->left = new_node;
        else
            trailing->right = new_node;
    }
    return new_node;
}

struct Parent_child_node inorder_predecessor(struct Node * node) {
    // rightmost child/node of the left subtree of the given node
    struct Parent_child_node output = {NULL, NULL};
    if (! node) 
        return output;
    if (! node->left) {
        output.parent = node;
        output.child = NULL;
    }
    struct Node * trailing = node;    
    node = node->left;
    while (node->right) {
        trailing = node;
        node = node->right;
    }
    output.parent = trailing;
    output.child = node;
    return output;
}

struct Parent_child_node inorder_successor(struct Node * node) {
    // leftmost child/node of the right subtree of the given node
    struct Parent_child_node output = {NULL, NULL};
    if (! node) 
        return output;
    if (! node->right) {
        output.parent = node;
        output.child = NULL;
        return output;
    }
    struct Node * trailing = node;
    node = node->right;
    while (node->left) {
        trailing = node;
        node = node->left;
    }
    output.parent = trailing;
    output.child = node;
    return output;
}

int height(struct Node * node) {
    if (! node)
        return -1;
    int x, y;
    x = height(node->left);
    y = height(node->right);
    if (x > y) 
        return x + 1;
    else 
        return y + 1;
}

int is_leaf(struct Node * node) {
    // 1 --> yes leaf | -1 --> not leaf
    if ( (node->left == NULL) && (node->right == NULL) ) 
        return 1;
    return 0;
}

struct Parent_child_node search_node_and_parent(struct Node * node, int data) {
    struct Parent_child_node output = {NULL, NULL};
    struct Node * trailing = NULL;
    while (node && node->data != data) {
        trailing = node;
        if (data < node->data) 
            node = node->left;
        else if (data > node->data)
            node = node->right;
    }
    if (node) {
        output.parent = trailing;
        output.child = node;
    }
    return output;
}

struct Node * delete(struct Node * node, int data) {
    if (! node) {
        // if root is NULL
        return NULL;
    }
    struct Parent_child_node node_and_parent = search_node_and_parent(node, data);
    struct Node * parent_of_to_delete = node_and_parent.parent;
    struct Node * to_delete = node_and_parent.child;
    if (! to_delete) {
        // the data isn't found in the tree, return the root passed to the function. Coz Nothing changed
        return node;
    }
    if (is_leaf(to_delete)) {
        // the to_delete node is a leaf node. Just disconnect the connection with parent
        if (parent_of_to_delete) {
            if (data < parent_of_to_delete->data) {
                parent_of_to_delete->left = NULL;
            } else {
                parent_of_to_delete->right = NULL;
            }
            free(to_delete);
            return node;
        } else {
            // no parent of to_delete node, means the node is the root and leaf, hence only node
            free(to_delete);
            return NULL;
        }
    }
    // the to_delete exists and it's not a leaf
    struct Node * to_replace = NULL;
    struct Node * parent_of_to_replace = NULL;
    struct Parent_child_node replacement;
    while (1) {
        if ( height(to_delete->left) > height(to_delete->right) ) {
            replacement = inorder_predecessor(to_delete);
        } else {
            replacement = inorder_successor(to_delete);
        }
        //printf("%d %d\n", replacement.parent->data, replacement.child->data);
        to_replace = replacement.child;
        if (! to_replace) 
            break;
        parent_of_to_replace = replacement.parent;
        to_delete->data = to_replace->data;
        to_delete = to_replace;
    }
    // parent_of_to_replace and to_delete should be disconnected and free(to_delete)
    if (to_delete->data < parent_of_to_replace->data) {
        parent_of_to_replace->left = NULL;
    } else {
        parent_of_to_replace->right = NULL;
    }
    free(to_delete);
    return node;
} 