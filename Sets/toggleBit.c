#include <stdio.h>
#include <stdlib.h>

typedef unsigned char SET;

void displayBit(SET x);
void toggleBit(SET *x, int num);


int main(void) {
    SET x = 'A';
    unsigned int num;

    printf("Original: ");
    displayBit(x);

    printf("Enter bit to toggle (1-8): ");
    scanf("%d", &num);
    printf("After: ");
    toggleBit(&x, num);
    displayBit(x);



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

void toggleBit(SET *x, int num) {
    if (num >= 0 && num < (sizeof(SET) * 8)) {
        *x ^= (1 << num);   // XOR toggles the bit
    }
}