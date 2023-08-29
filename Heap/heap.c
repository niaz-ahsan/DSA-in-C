// Max Heap

#include <stdio.h>
#include <stdlib.h>

struct Heap {
    int * heap;
    int size;
};

void insert_at_heap(struct Heap * h, int val);
void display(struct Heap * h);

int main(void) {
    int arr[7] = {70, 60, 85, 1000, 30, 40, 75};
    int size = 7;
    struct Heap h;
    h.heap = (int *) malloc(size * sizeof(int));
    h.size = 0;
    for (int i=0; i<size; i++) {
        insert_at_heap(&h, arr[i]);
    }
    display(&h);
    return 0;
}
 
int initial_insert_at_heap(struct Heap * h, int val) {
    h->heap[h->size] = val;
    h->size++;
    return h->size;
} 

int get_element_at_index(struct Heap * h, int index) {
    return h->heap[index - 1];
}

void swap(struct Heap * h, int i1, int i2) {
    int temp = h->heap[i1-1];
    h->heap[i1-1] = h->heap[i2-1];
    h->heap[i2-1] = temp;
}

void adjust_element_position(struct Heap * h, int index) {
    int parent_index = index / 2;
    if (parent_index < 1) {
        // index is 1st element, no adjustment needed
        return;
    } 
    // adjusting the new element position
    while (index > 1 && get_element_at_index(h, index) > get_element_at_index(h, parent_index)) {
        swap(h, index, parent_index);
        index = parent_index;
        parent_index = index / 2;
    }
}

void insert_at_heap(struct Heap * h, int val) {
    int new_index = initial_insert_at_heap(h, val);
    adjust_element_position(h, new_index);
}

void display(struct Heap * h) {
    for (int i=0; i<h->size; i++) {
        printf("%d ", h->heap[i]);
    }
    printf("\n");
}