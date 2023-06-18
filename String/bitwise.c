/*
practice bitwise Masking & Merging
*/

#include <stdio.h>
#include <stdlib.h>

void masking(char c, short bit);
void to_binary(char c);

int main(void) {
    char c;
    short ascii;
    short chk_bit;
    printf("Provide an input in the range (inclusive) [0 - 255]\n");
    scanf("%hd", &ascii);
    c = (char) ascii;
    printf("Char you saved: %c\n", c);
    to_binary(c);
    printf("Which bit do you want to check? [0-7]\n");
    scanf("%hd", &chk_bit);
    if (chk_bit < 0 || chk_bit > 7) {
        printf("bit is out of range\n");
        exit(1);
    }
    masking(c, chk_bit);
    return 0;
}

void to_binary(char c) {
    printf("Binary you saved:");
    for (int i=7; i>=0; i--) {
        putchar( (c & (1 << i))? '1':'0' );
        putchar(' ');
    }
    putchar('\n');
}

void masking(char c, short bit) {
    if (c & (1 << bit)) {
        printf("It is a 1\n");
        return;
    } 
    printf("It is a 0\n");    
}