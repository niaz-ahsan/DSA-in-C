/*
Using masking to print binary
Masking: data & (1 << the bit you want to check)
*/
#include <stdio.h>
 
int main()
{
    short num;
    printf("Provide input (0-255):\n");
    scanf("%hd", &num);
    for (int i=7; i>=0; i--) {
        // starting from LSB
        putchar( (num & (1 << i))? '1':'0' ); // check Bitwise operation in Notes
    }
    putchar('\n');

    return 0;
}