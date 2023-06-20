#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

// global var
struct Node *head = NULL;
struct Node *tail = NULL;
int length = 0;

// func prototypes
void generate_list(int * arr, int size);
void display_list();
void push(int);
void insert(int data, int position);
struct Node * search(int);
void delete(int);

int main(void) {
    int arr[] = {3, 5, -1, 2, 1000, -99};
    generate_list(arr, 6);
    //display_list();
    insert(-69, 0);
    //display_list(); 
    insert(-69, 2);
    //display_list();
    insert(-69, 9);
    //display_list();
    push(420);
    push(923);
    display_list();
    delete(1);
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
        length = size;
    } 
}

void display_list() {
    struct Node * current = head;
    printf("========================================\n");
    printf("Length: %d\n", length);
    while(current != NULL) {
        printf("%d --> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    printf("========================================\n");
}

void push(int data) {
    if (head) {
        struct Node * current = (struct Node *) malloc(sizeof(struct Node));
        current->data = data;
        current->next = NULL;
        tail->next = current;
        tail = current;
        length++;
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

void insert(int data, int position) {
    // In LL considering 1st Node is index 1, 2nd in index 2, ...
    /*
    position 0 - head node
    position 1 - add after node 1
    position 2 - add after node 2
    ...
    */
    struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (position == 0) {
        if (head) {
            new_node->next = head;
            head = new_node;
            length++;
            return;
        }
        head = new_node;
        tail = new_node;
        length++;
        return;
    }
    int index = 1;
    struct Node * current = head;
    if (current) {
        // LL exists and position > 0 
        while (index < position && current != NULL) {
            current = current->next;
            index++;
        }
        //printf("index: %d\n", index);
        if (index == position && current) {
            // expected
            struct Node * next = current->next;
            current->next = new_node;
            new_node->next = next;
        } else {
            // LL ended before that position reached, hence call push()
            tail->next = new_node;
            tail = new_node;
        }
    } else {
        // LL doesn't exist and position > 0 ... abnormal. Hence put it in the head (position 0)
        head = new_node;
        tail = new_node;
    }
    length++;
}

void delete_node(struct Node * prev, struct Node * node) {
    if (node == head) {
        head = head->next;
        free(node);
    } else {
        prev->next = node->next;
        if(node == tail) {
            tail = prev;
        }
        free(node);
    }
    length--;
}

void delete(int position) {
    // In LL considering 1st Node is index 1, 2nd in index 2, ... and that's what we'll be deleting
    if (position < 1 || position > length ) {
        return;
    }
    if (position == 1) {
        delete_node(NULL, head);
        return;
    }   
    struct Node * current = head;
    for (int i=0; i<position-2; i++) {
        current = current->next;
    }
    delete_node(current, current->next);
}