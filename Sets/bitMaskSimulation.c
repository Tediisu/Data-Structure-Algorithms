#include <stdio.h>

typedef unsigned int SET;

void add(SET *x, int num);
void remove_num(SET *x, int num);
int isMember(SET x, int num);
void displayBit(SET x);

int main(void) {
    SET x = 0;
    int y = 4;

    //add 2, 4, 7 into the SET x;
    add(&x, 2);
    add(&x, 4);
    add(&x, 7);
    displayBit(x);

    int bool = isMember(x, y);
    if (bool == 1) {
        printf("%d is a member of SET x\nRemoving...\n", y);
        remove_num(&x, y);
        displayBit(x);
    } else
        printf("%d is not a member of SET x\n", y);


    return 0;
}

void add(SET *x, int num) {
    if (num >= 0 && num < (sizeof(SET) * 8 -1 )) {
        *x ^= (1 << num);
    }
}
void remove_num(SET *x, int num) {
    if (num >= 0 && num < (sizeof(SET) * 8 - 1)) {
        *x &= ~(1 << num);
    }
}
int isMember(SET x, int num) {
    if (num >= 0 && num < (sizeof(SET) * 8 - 1)) {
        x == (1 << num);
        return 1;
    } else
        return 0;
}

void displayBit(SET x) {
    SET mask = 1 << (sizeof(SET) * 2 - 1);

    while (mask != 0) {
        printf("%d", (mask & x) ? 1 : 0);
        mask >>= 1;
    }
    
    printf("\n");
}