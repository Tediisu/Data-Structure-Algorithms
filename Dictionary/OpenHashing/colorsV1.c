//A Bunch of Confusing Pointer/Asterisk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 10

typedef struct Node {
    char hex[32];
    char name[32];
    struct Node *next;
} Color, *ColorPtr;

void initList(ColorPtr **L); //think of this as a double pointer with a pointer data type
int get_NumOfBits(int x);
int get_SumOfLetters(char *key);
unsigned int hash(Color data);
void insert(ColorPtr **L, Color data);
void populate(ColorPtr **L);
void display(ColorPtr *L); //This is the same as ColorPtr L[] which is an array of pointers


int main(void) {
    ColorPtr *cList;

    initList(&cList);
    populate(&cList);
    display(cList);

    return 0;
}

void initList(ColorPtr **L) {
    *L = malloc(sizeof(ColorPtr) * MAX);
    if (!(*L)) return;

    for (int i = 0; i < MAX; i++) {
        (*L)[i] = NULL;
    }

}

int get_NumOfBits(int x) {
    unsigned int mask = 1 << (sizeof(int) * 8 - 1);
    int num = 0;

    for (; mask != 0; mask >>= 1) {
        if (x & mask) num++;
    }

    return num;
}

int get_SumOfLetters(char *key) {
    int length = strlen(key);
    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += key[i];
    }

    return sum;
}

unsigned int hash(Color data) {
    return ((get_NumOfBits(get_SumOfLetters(data.hex)) * get_SumOfLetters(data.name) + 31)) % MAX;
}

void insert(ColorPtr **L, Color data) {
    int nDx = hash(data);

    if ((*L)[nDx] != NULL) {
        ColorPtr temp = malloc(sizeof(Color));
        if (!temp) return;

        strcpy(temp->hex, data.hex);
        strcpy(temp->name, data.name);
        temp->next = (*L)[nDx];
        (*L)[nDx] = temp;

        return;
    }

    (*L)[nDx] = malloc(sizeof(Color));
    if (!(*L)[nDx]) return;

    strcpy((*L)[nDx]->hex, data.hex);
    strcpy((*L)[nDx]->name, data.name);
    (*L)[nDx]->next = NULL;

}

void populate(ColorPtr **L) {
    Color colors[13] = {
      {"#FF0000", "Red"}, {"#00FF00", "Green"}, {"#0000FF", "Blue"},
      {"#FFFF00", "Yellow"}, {"#FFA500", "Orange"}, {"#800080", "Purple"},
      {"#00FFFF", "Cyan"}, {"#FFC0CB", "Pink"}, {"#808080", "Gray"},
      {"#000000", "Black"}, {"#FFFFFF", "White"}, {"#A52A2A", "Brown"},
      {"#008000", "Dark Green"}
    };
    int length = sizeof(colors) / sizeof(colors[0]);

    for (int i = 0; i < length; i++) {
        insert(L, colors[i]);
    }


}

void display(ColorPtr *L) {
    printf("Table:\n");
    printf("\t%-4s%7s\n", "nDx", "Head");

    for (int i = 0; i < MAX; i++) {
        printf("\t%2d   ", i);
        if (L[i] == NULL) {
            printf("[ NULL ]");
        } else 
            printf("[ LINK ]");
            ColorPtr temp = L[i];
            while (temp != NULL) {
                printf(" -> [ %-8s %s ]", temp->hex, temp->name);
                temp = temp->next;
            }
        printf("\n");
    }

}