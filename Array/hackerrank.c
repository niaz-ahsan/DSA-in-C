// Problem: https://www.hackerrank.com/challenges/dynamic-array-in-c/problem?isFullScreen=false

#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int * total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int ** total_number_of_pages;

int arr_initiated = 0;

void init_array(int total_shelves) {
    total_number_of_pages = (int **) malloc(total_shelves * sizeof(int *));
    total_number_of_books = (int *) calloc(total_shelves, sizeof(int));
}

void display_arr(int total_shelves) {
    for (int i=0; i<total_shelves; i++) {
        for (int j=0; j<total_number_of_books[i]; j++) {
            printf("%d ", total_number_of_pages[i][j]);
        }
        printf("\n");
    }
}

void insert_book(int shelf, int page_count, int total_shelves) {
    if (shelf >= total_shelves) {
        return;
    }
    total_number_of_books[shelf]++;
    total_number_of_pages[shelf] = (int *) realloc(total_number_of_pages[shelf], total_number_of_books[shelf] * sizeof(int));
    // just insert the book
    int inserting_position = total_number_of_books[shelf] - 1;
    total_number_of_pages[shelf][inserting_position] = page_count;   
}

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    if (! arr_initiated) {
        init_array(total_number_of_shelves);
    }

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            insert_book(x, y, total_number_of_shelves);
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    display_arr(total_number_of_shelves);

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}