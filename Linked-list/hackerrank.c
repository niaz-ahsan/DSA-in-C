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


