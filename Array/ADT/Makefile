# abstract_data_type.c --> main.o
# quicksort.c --> sort.o
# binary_search.c --> search.o

execute_me: main.o sort.o search.o
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra main.o sort.o search.o -o execute_me
	
main.o: abstract_data_type.c 
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c -o main.o abstract_data_type.c
	
sort.o: quicksort.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c -o sort.o quicksort.c

search.o: binary_search.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c -o search.o binary_search.c	