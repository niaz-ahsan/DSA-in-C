#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; // considering queue would hold int data
    struct Node * next;
};

struct Queue {
    int len;
    struct Node * first; // deletion/dequeue at first
    struct Node * last; // insertion/enqueue at last
};

void init_queue(struct Queue *);
void enqueue(struct Queue *, int);
void display(struct Queue *);
int dequeue(struct Queue *);

int main(void) {
    struct Queue q;
    init_queue(&q);
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    return 0;
}

void init_queue(struct Queue * q) {
    q->len = 0;
    q->first = NULL;
    q->last = NULL;
}

void enqueue(struct Queue * q, int data) {
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    if (node == NULL) {
        // Heap memory is full
        printf("No more space at Heap\n");
        return;
    } 
    node->data = data;
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

int dequeue(struct Queue * q) {
    // -1 if q is empty, int data otherwise
    if (q->first == NULL) {
        // q is empty
        printf("Queue is empty!\n");
        return -1;
    }
    int ret = q->first->data;
    struct Node * to_be_deleted = q->first;
    q->first = q->first->next;
    free(to_be_deleted);
    q->len--;
    return ret;
}

void display(struct Queue * q) {
    printf("=============== QUEUE DISPLAY START ===============\n");
    printf("Length: %d\n", q->len);
    struct Node * current = q->first;
    while(current != NULL) {
        printf("%d -->", current->data);
        current = current->next;
    }
    printf("\n");
    if(q->len) {
        printf("[first] pointing at: %d\n", q->first->data);
        printf("[last] pointing at: %d\n", q->last->data);
    }
    printf("================ QUEUE DISPLAY END ================\n");
}