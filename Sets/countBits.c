#include <stdio.h>

typedef unsigned char SET;

void displayBit(SET x);
int countBits(SET x);

int main(void) {
    SET a = 'A';

    displayBit(a);
    printf("%d", countBits(a));


    return 0;
}

void displayBit(SET x) {
    SET mask = 1 << (sizeof(SET) * 8 - 1);

    while (mask != 0) {
        printf("%d", (mask & x) ? 1 : 0);
        mask >>= 1;
    }

    printf("\n");
}

int countBits(SET x) {
    SET mask = 1 << (sizeof(SET) * 8 - 1);
    int ctr = 0;

    while (mask != 0) {
        if (mask & x) ctr++;
        mask >>= 1;
    }

    return ctr;
}