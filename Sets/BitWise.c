#include <stdio.h>

void printBinary(unsigned char X);
void do_Operations(unsigned char X, unsigned char Y);

int main(void) {
    unsigned char x;
    unsigned char y;

    printf("Enter two characters: ");
    scanf(" %c %c", &x, &y);

    printBinary(x);
    printBinary(y);

    do_Operations(x, y);

    return 0;
}

void printBinary(unsigned char X) {
    unsigned char mask = 1 << (sizeof(char) * 8 - 1);

    printf("%c = ", X);
    while (mask != 0) {
        printf("%d", (mask & X) ? 1 : 0);
        mask >>= 1;
    }
    
    printf("\n");
}

void do_Operations(unsigned char X, unsigned char Y) {
    unsigned char mask;

    printf("%c & %c = ", X, Y);
    mask = 1 << (sizeof(char) * 8 - 1);
    while (mask != 0) {
        printf("%d", ((X & Y) & mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");

    printf("%c | %c = ", X, Y);
    mask = 1 << (sizeof(char) * 8 - 1);
    while (mask != 0) {
        printf("%d", ((X | Y) & mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");

    printf("%c ^ %c = ", X, Y);
    mask = 1 << (sizeof(char) * 8 - 1);
    while (mask != 0) {
        printf("%d", ((X ^ Y) & mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");

    printf("~%c & %c = ", X, Y);
    mask = 1 << (sizeof(char) * 8 - 1);
    while (mask != 0) {
        printf("%d", (((~X) & Y) & mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");
    

}
