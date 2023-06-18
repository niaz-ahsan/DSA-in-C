/*
practice bitwise Masking & Merging
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char c;
    int ascii;
    short chk_bit;
    printf("Provide an input in the range (inclusive) [0 - 255]\n");
    scanf("%d", &ascii);
    c = (char) ascii;
    printf("Which bit do you want to check? [0-7]\n");
    scanf("%hd", &chk_bit);
    if (chk_bit < 0 || chk_bit > 7) {
        printf("bit is out of range\n");
        exit(1);
    }

    return 0;
}