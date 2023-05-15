#include <stdio.h>
#include <stdlib.h>

void initiate_array(int **, int, int);
void print_array(int **, int, int);
int ** allocate_memory_for_rows(int **, int);
void free_memory(int ***, int);

int main(int argc, char * argv[]) {
    if (argc < 3) {
        printf("Format: ./<exe> <row_count> <col_count>\n");
        return 0;
    }  
    int row = atoi(argv[1]);
    int col = atoi(argv[2]);

    int **ptr;
    // allocating memory space
    ptr = allocate_memory_for_rows(ptr, row);   
    if (ptr) {
        // access each row, allocate memory and assign value from user input
        initiate_array(ptr, row, col);
        // print the 2D Array
        print_array(ptr, row, col);
        // free up memory
        free_memory(&ptr, row);
    }  
    return 0;
}

int ** allocate_memory_for_rows(int ** ptr, int row) {
    ptr = (int **) malloc(row * sizeof(int *));
    if (ptr) {
        return ptr;
    }
    return NULL;
}

void initiate_array(int ** ptr, int row, int col) {
    int i;
    for (i=0; i<row; i++) {
        int *c = (int *) malloc(col * sizeof(int));
        int j;
        for (j=0; j<col; j++) {
            int num;
            printf("[%d][%d] Data: \n", i, j);
            scanf("%d", &num);
            printf("\n");
            c[j] = num;
        }
        ptr[i] = c;
    }
}

void print_array(int ** ptr, int row, int col) {
    printf("The values are following:\n");
    int i;
    for (i=0; i<row; i++) {
        int j;
        for (j=0; j<col; j++) {
            printf("%d  ", ptr[i][j]);
        }
        printf("\n");
    }
}

void free_memory(int *** ptr, int row) {
    //printf("%d\n", ptr[0][0][0]);
    int i;
    for (i=0; i<row; i++) {
        free(ptr[0][i]);
    }
    free(ptr[0]);
}