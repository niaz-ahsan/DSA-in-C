#include <stdio.h>
#include <stdarg.h>

void print_nums(int count, ...) {
    va_list list;
    va_start(list, count);
    for (int i=0; i<count; i++) {
        int val = va_arg(list, int);
        printf("[%d]: %d\n", i, val);
    }
    va_end(list);
}

int main() {
    print_nums(3, 12, 15, 17);
    print_nums(2, 100, 999);
    return 0;
}