#include <stdio.h>
#include <stdlib.h>

struct Node {
    char * data; // considering tree would have char
    struct tree_node * left_child;
    struct tree_node * right_child;
};

struct Q_node {
    struct Node * tree_node;
    struct Q_node * next;
};

struct Queue {
    int len;
    struct Q_node * first;
    struct Q_node * last;
};

void init_queue(struct Queue * q);
void enqueue(struct Queue * q, struct Node * data);
struct Node * dequeue(struct Queue * q); 
void display(struct Queue * q);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Syntax: <exe> <data separated by space level by level e.g. 5 4 3 100 null 2 1 101 102 null null>\n");
        exit(1);
    }
    struct Queue q;
    init_queue(&q);
    for (int i=1; i<argc; i++) {
        // looping through chars 
        char * data = argv[i];
        printf("%s\n", data);
    }

    return 0;
}


// ################### Queue related functions ##########################

void init_queue(struct Queue * q) {
    q->len = 0;
    q->first = NULL;
    q->last = NULL;
}

void enqueue(struct Queue * q, struct Node * data) {
    struct Q_node * node = (struct Q_node *) malloc(sizeof(struct Q_node));
    if (node == NULL) {
        // Heap memory is full
        printf("No more space at Heap\n");
        return;
    } 
    node->tree_node = data;
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

struct Node * dequeue(struct Queue * q) {
    // -1 if q is empty, data otherwise
    if (q->first == NULL) {
        // q is empty
        printf("Queue is empty!\n");
        return NULL;
    }
    struct Node * ret = q->first->tree_node;
    struct Q_node * to_be_deleted = q->first;
    q->first = q->first->next;
    free(to_be_deleted);
    q->len--;
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