#include <stdio.h>
#include <string.h>

int length(char *);
void to_upper(char *);
int word_count(char *);
void frequency(char *);
void to_lower(char *);

int main(void) {
    char str[50];
    printf("Provide the string: \n");
    gets(str);
    
    // length of string
    printf("Length: %d\n", length(str));
    
    // convert string to uppercase
    to_upper(str);
    printf("After changing to all upper: %s\n", str);

    // count the words
    printf("Total words: %d\n", word_count(str));

    // checking char freq
    frequency(str);

    return 0;
}

int length(char * s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void to_upper(char * s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 97 && s[i] <= 122) {
            // change case only if the char is from a-z
            s[i] = s[i] - 32;
        }
        i++;
    }
}

void to_lower(char * s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 65 && s[i] <= 90) {
            // change case only if the char is from a-z
            s[i] = s[i] + 32;
        }
        i++;
    }
}

int word_count(char * s) {
    // iterate through the string and check for space followed by a char (upper or lower case)
    int i = 0;
    int word_count = 0;
    int is_alphabet;
    while (s[i] != '\0') {
        is_alphabet = (s[i+1] >= 97 && s[i+1] <= 122) || (s[i+1] >= 65 && s[i+1] <= 90);
        if  ( (s[i] == 32 && is_alphabet) || (i == 0 && is_alphabet) ) {
            word_count++;
        }
        i++;
    }
    return word_count;
} 

void frequency(char * s) {
    int freq[26] = {0};
    to_lower(s);
    int i = 0;
    while (s[i] != '\0') {
        int index = s[i] - 97;
        freq[index]++;
        i++;
    }
    for (i = 0; i<26; i++) {
        if (freq[i] > 1) {
            printf("'%c' occurred: %d\n", i+97, freq[i]);
        }
    }
}


