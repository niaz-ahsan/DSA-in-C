#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Format: ./<exe> <array size>\n");
		return 0;
	}
	int size = atoi(argv[1]);
	if (size <= 0) {
		printf("No space allocated!\n");
		return 0;
	}
	
	// taking user input
	int *ptr;
	ptr = (int *) malloc(size * sizeof(int));
	if (ptr == NULL) {
		printf("Memory Allocation failed!!!\n");
		return 0;
	}
	int i;
	for (i=0; i<size; i++) {
		int num;
		printf("%d: What's the data? ", i+1);
		scanf("%d", &num);
		ptr[i] = num;
		printf("\n");
	}
	// printing output
	printf("Data you've entered is following:\n");
	for (i=0; i<size; i++) {
		printf("%d ", ptr[i]);
	}
    printf("\n");
	free(ptr);
	return 0;
}