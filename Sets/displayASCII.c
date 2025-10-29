#include <stdio.h>
#include <stdlib.h>

void displayBinary(char x);

int main(void) {
    unsigned char letter;

    printf("Enter a single letter: ");
    scanf(" %c", &letter);

    displayBinary(letter);

    return 0;
}

void displayBinary(char x) {
    unsigned char mask = 1 << sizeof(char) * 8 - 1;

    while (mask != 0) {
        printf("%d", (mask & x) ? 1 : 0);
        mask >>= 1;
    }
}