#include <stdio.h>

int search(int * ptr, int low, int high, int data) {
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (ptr[mid] == data) {
            return mid;
        } else if (data > ptr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // at this point data wasn't found
    return -1;
}