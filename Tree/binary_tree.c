#include <stdio.h>
#include <stdlib.h>

struct tree_node {
    int data; // considering tree would have int
    struct tree_node * left_child;
    struct tree_node * right_child;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Syntax: <exe> <data separated by space level by level e.g. 5 4 3 100 null 2 1 101 102 null null>\n");
        exit(1);
    }

    return 0;
}