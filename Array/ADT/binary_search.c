#include <stdio.h>

int search(int * ptr, int low, int high, int data) {
    int mid;
    int hops = 0; // to see # of iteration
    int found = 0;
    while (low <= high) {
        hops++;
        mid = (low + high) / 2;
        if (ptr[mid] == data) {
            found = 1;
            break;
        } else if (data > ptr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    printf("Total hops: %d\n", hops);
    if (found) {
        return mid;
    } else {
        return -1;
    }    
}

int rec_search(int * ptr, int low, int high, int data) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (data == ptr[mid]) {
        return mid;
    } else if (data > ptr[mid]) {
        low = mid + 1;
        return rec_search(ptr, low, high, data);
    } else {
        high = mid - 1;
        return rec_search(ptr, low, high, data);
    }
}