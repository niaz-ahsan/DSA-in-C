#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void display(struct Node * head) {
    struct Node * curr = head;
    while (curr) {
        printf("%d --> ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int has_cycle(struct Node * head) {
    // hare & tortoise algo, 1 if cycle, 0 if no cycle
    int found = 0;
    struct Node * hare = head;
    struct Node * tort = head;
    if (! head) 
        return found;
    while (1) {
        tort = tort->next;
        if (hare && hare->next) {
            hare = hare->next->next;
        } else {
            break;
        }
        if(hare == tort) {
            found = 1;
            break;
        }
    }
    return found;
}

int main(void) {
    struct Node a = {1, NULL};
    struct Node b = {2, NULL};
    struct Node c = {3, NULL};
    // creating the list
    struct Node * head = &a;
    a.next = &b;
    b.next = NULL;
    //c.next = &b;
    //c.next = NULL;
    display(head);
    printf("Cycle there: %d\n", has_cycle(head));

    return 0;
}