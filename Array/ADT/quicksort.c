#include <stdio.h>

void quicksort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void swap(int *a, int *b);

// Time O(nlogn)
void quicksort(int *arr, int low, int high) {
	if (low < high) {
		int pivot_location = partition(arr, low, high);
		quicksort(arr, low, pivot_location-1);
		quicksort(arr, pivot_location+1, high);
	}
}

int partition(int *arr, int low, int high) {
	int pivot_location = high;
	int i = low - 1;
	int j;
	for (j=low; j<=pivot_location-1; j++) {
		//if arr[j] > arr[pivot_location] do nothing
		if (arr[j] < arr[pivot_location]) {
			i++;
			if (i != j) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
	swap(&arr[pivot_location], &arr[i+1]);
	pivot_location = i + 1;
	return pivot_location;
}


void swap(int *a, int *b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

