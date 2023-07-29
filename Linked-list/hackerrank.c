/*
Contains all functions as solution of Hackerrank Linked List related problems
*/

#include <stdio.h>

struct SinglyLinkedList {
    struct SinglyLinkedListNode * head;
    struct SinglyLinkedListNode * tail;
};

struct SinglyLinkedListNode {
    int data;
    struct SinglyLinkedListNode * next;
};

// Problem: Print the Elements of a Linked List
// link: https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem

void printLinkedList(struct SinglyLinkedListNode * head) {
    if (!head) {
        return;
    }
    struct SinglyLinkedListNode * current = head;
    while (current) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Problem: Insert a Node at the Tail of a Linked List
// link: https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem 

struct SinglyLinkedListNode * insertNodeAtTail(struct SinglyLinkedListNode * head, int data) {
    struct SinglyLinkedListNode * node = (struct SinglyLinkedListNode *) malloc (sizeof(struct SinglyLinkedListNode));
    node->data = data;
    node->next = NULL;
    if (!head) {
        // if no head, make it head;
        return node;
    } 
    struct SinglyLinkedListNode * current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = node;
    return head;
}

// Problem: Insert a node at the head of a linked list
// link: https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem 

struct SinglyLinkedListNode * insertNodeAtHead(struct SinglyLinkedListNode * llist, int data) {
    struct SinglyLinkedListNode * node = (struct SinglyLinkedListNode *) malloc(sizeof(struct SinglyLinkedListNode));
    node->data = data;
    node->next = NULL;
    if (! llist) {
        // if no head, new node is the head
        return node;
    }
    node->next = llist;
    llist = node;
    return llist;
}

// Problem: Insert a node at a specific position in a linked list
// link: https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem 

struct SinglyLinkedListNode * insertNodeAtPosition(struct SinglyLinkedListNode * llist, int data, int position) {
    struct SinglyLinkedListNode * node = (struct SinglyLinkedListNode *) malloc(sizeof(struct SinglyLinkedListNode));
    node->data = data;
    node->next = NULL;
    struct SinglyLinkedListNode * current = llist;
    for (int i=0; i<position-1; i++) {
        current = current->next;
    }
    struct SinglyLinkedListNode * temp = current->next;
    current->next = node;
    node->next = temp;
    return llist;
}

// Problem: Delete a Node
// link: https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem

struct SinglyLinkedListNode * deleteNode(struct SinglyLinkedListNode * llist, int position) {
    if (position == 0) {
        struct SinglyLinkedListNode * to_del = llist;
        llist = llist->next;
        free(to_del);
        return llist;
    }
    struct SinglyLinkedListNode * current = llist;
    for (int i=0; i<position-1; i++) {
        current = current->next;
    }
    struct SinglyLinkedListNode * to_del = current->next;
    if(to_del) {
        current->next = to_del->next;
        free(to_del);
    }
    return llist;
}

// Problem: Print in Reverse
// link: https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem

void reversePrint(struct SinglyLinkedListNode * llist) {
    struct SinglyLinkedListNode * prev = NULL;
    struct SinglyLinkedListNode * curr = llist;
    struct SinglyLinkedListNode * next = curr->next;
    while (1) {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next)
            next = next->next;
        else
            break;
    }
    llist = prev;
    //printf("%d\n", llist->data);
    struct SinglyLinkedListNode * current = llist;
    while (current) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Problem: Reverse a linked list
// link: https://www.hackerrank.com/challenges/reverse-a-linked-list/problem

struct SinglyLinkedListNode * reverse(struct SinglyLinkedListNode * llist) {
    struct SinglyLinkedListNode * prev = NULL;
    struct SinglyLinkedListNode * curr = llist;
    struct SinglyLinkedListNode * next = curr->next;
    while (1) {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next)
            next = next->next;
        else
            break;
    }
    llist = prev;
    return llist;
}

// Problem: Compare two linked lists
// link: https://www.hackerrank.com/challenges/compare-two-linked-lists/submissions/code/338074400 

bool compare_lists(struct SinglyLinkedListNode * head1, struct SinglyLinkedListNode * head2) {
    struct SinglyLinkedListNode * curr1 = head1;
    struct SinglyLinkedListNode * curr2 = head2;
    while (curr1 && curr2) {
        if (curr1->data != curr2->data) {
            // break;
            return 0;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return (curr1 == curr2)?  1 : 0;
}

// Problem: Merge two sorted linked lists
// link: https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/copy-from/338094476

struct NewLL {
    struct SinglyLinkedListNode * head;
    struct SinglyLinkedListNode * tail;
}; 

void push_to_new_list(struct NewLL * newList, int data) {
    struct SinglyLinkedListNode * node = (struct SinglyLinkedListNode *) malloc(sizeof(struct SinglyLinkedListNode));
    node->data = data;
    node->next = NULL;
    if (!newList->head || !newList->tail) {    
        newList->head = node;
        newList->tail = node;
        return;
    }
    newList->tail->next = node;
    newList->tail = node;
}
 
struct SinglyLinkedListNode * mergeLists(struct SinglyLinkedListNode * head1, struct SinglyLinkedListNode * head2) {
    struct SinglyLinkedListNode * curr1 = head1;
    struct SinglyLinkedListNode * curr2 = head2;
    struct NewLL * newList = (struct NewLL *) malloc(sizeof(struct NewLL));
    newList->head = NULL;
    newList->tail = NULL;
    while (curr1 && curr2) {
        if (curr1->data < curr2->data) {
            // push curr1->data to the new list;
            push_to_new_list(newList, curr1->data);
            curr1 = curr1->next;
        } else {
            // push curr2->data to the new list;
            push_to_new_list(newList, curr2->data);
            curr2 = curr2->next;
        }
    } 
    while (curr1) {
        // push curr1->data to the new list
        push_to_new_list(newList, curr1->data);
        curr1 = curr1->next;
    }
    while (curr2) {
        // push curr2->data to the new list;
        push_to_new_list(newList, curr2->data);
        curr2 = curr2->next;
    }
    return newList->head;
}

// Problem: Get Node Value
// link: https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/copy-from/338131964 

void push(struct SinglyLinkedList * stack, int data) {
    struct SinglyLinkedListNode * node = (struct SinglyLinkedListNode *) malloc(sizeof(struct SinglyLinkedListNode));
    node->data = data;
    node->next = NULL;
    if (!stack->head) {
        // stack is empty
        stack->head = node;
        stack->tail = node;
    }
    node->next = stack->head;
    stack->head = node;
}

int pop(struct SinglyLinkedList * stack) {
    // -1 if no data in stack
    if (!stack->head) {
        return -1;
    }
    struct SinglyLinkedListNode * node = stack->head;
    stack->head = node->next;
    int ret = node->data;
    free(node);
    return ret;
}

int getNode(struct SinglyLinkedListNode * llist, int positionFromTail) {
    struct SinglyLinkedList * stack = (struct SinglyLinkedList *) malloc(sizeof(struct SinglyLinkedList));
    stack->head = NULL;
    stack->tail = NULL;
    struct SinglyLinkedListNode * current = llist;
    while (current) {
        push(stack, current->data);
        current = current->next;
    }
    int output;
    for (int i=0; i<=positionFromTail; i++) {
        output = pop(stack);
    }
    return output;
}

// Problem: Delete duplicate-value nodes from a sorted linked list
// link: https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/copy-from/338188953 

struct SinglyLinkedListNode * removeDuplicates(struct SinglyLinkedListNode * llist) {
    struct SinglyLinkedListNode * prev = NULL;
    struct SinglyLinkedListNode * curr = llist;
    while(curr) {
        if (prev) {
            if (prev->data == curr->data) {
                prev->next = curr->next;
                curr = curr->next;
                continue;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    return llist;
}

// Problem: Cycle Detection
// link: https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/copy-from/338252402

bool has_cycle(struct SinglyLinkedListNode * head) {
    bool found = 0;
    struct SinglyLinkedListNode * hare = head;
    struct SinglyLinkedListNode * tort = head;
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