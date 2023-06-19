#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

// global var
struct Node *head = NULL;
struct Node *tail = NULL;

// func prototypes
void generate_list(int * arr, int size);
void display_list();

int main(void) {
    int arr[] = {3, 5, -1, 2, 1000, -99};
    generate_list(arr, 6);
    display_list();
    return 0;
}

void generate_list(int * arr, int size) {
    struct Node * current = NULL; 
    if (size > 0) {
        head = (struct Node *) malloc(sizeof(struct Node));
        head->data = arr[0];
        head->next = NULL;
        tail = head;
        for (int i=1; i<size; i++) {
            current = (struct Node *) malloc(sizeof(struct Node));
            current->data = arr[i];
            current->next = NULL;
            tail->next = current;
            tail = current;
        }
    } 
}

void display_list() {
    struct Node * current = head;
    while(current != NULL) {
        printf("%d --> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
