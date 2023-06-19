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
void push(int);
struct Node * search(int);

int main(void) {
    int arr[] = {3, 5, -1, 2, 1000, -99};
    generate_list(arr, 6);
    push(420);
    push(923);
    display_list();
    (search(420))? printf("420 Found!\n") : printf("420 Not Found!\n");
    (search(1))? printf("1 Found!\n") : printf("1 Not Found!\n");
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

void push(int data) {
    if (head) {
        struct Node * current = (struct Node *) malloc(sizeof(struct Node));
        current->data = data;
        current->next = NULL;
        tail->next = current;
        tail = current;
        return;
    }     
    int arr[] = {data};
    generate_list(arr, 1);
}

struct Node * search(int data) {
    struct Node * current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
