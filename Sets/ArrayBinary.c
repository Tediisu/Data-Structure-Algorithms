#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef unsigned int SET;

SET *convert_ToBinary(SET L[]);
void displaySetArr(SET L[]);


int main(void) {
    SET nums[MAX] = {10, 20, 30, 40, 50};
    SET *Binary;

    displaySetArr(nums);


    return 0;
}

// SET *convert_ToBinary(SET L[]) { // to do later
//     SET *temp = malloc(sizeof(SET) * MAX);
//     if (!temp) return NULL;

//     SET mask = 1 << sizeof(SET) * 8 - 1;
//     SET value = 0; //temporarily stores the bits
//     int nDx = 0;

//     for (int i = 0; i < MAX; i++) {

//     }

// }

void displaySetArr(SET L[]) {
    for (int i = 0; i < MAX; ) {
        printf("[%d] = ", L[i]);
        
        SET mask = 1 << (sizeof(SET) * 8 - 1);
        while (mask != 0) {
            printf("%d", (mask & L[i]) ? 1 : 0);
            mask >>= 1;
        }
        i++;
        printf("\n");
    }
    
}