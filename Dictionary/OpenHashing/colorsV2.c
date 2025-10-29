#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    char hex[32];
    char name[32];
    struct Node *next;
} Color, *ColorPtr;

void initList(ColorPtr L[]);
void populate(ColorPtr L[]);
ColorPtr createNode(Color data);
int get_NumOfBits(int x);
int get_SumOfLetters(char *key);
unsigned int hash(Color data);
void insert(ColorPtr L[], Color data);
void display(ColorPtr L[]);

int main(void) {
    ColorPtr List[MAX];

    initList(List);
    populate(List);


    display(List);



    return 0;
}

void initList(ColorPtr L[]) {
    for (int i = 0; i < MAX; i++) {
        L[i] = NULL;
    }

}

ColorPtr createNode(Color data) {
    ColorPtr temp = malloc(sizeof(Color));
    if (!temp) return NULL;

    strcpy(temp->hex, data.hex);
    strcpy(temp->name, data.name);
    temp->next = NULL;

    return temp;
}

void populate(ColorPtr L[]) {
    Color colors[13] = {
      {"#FF0000", "Red"}, {"#00FF00", "Green"}, {"#0000FF", "Blue"},
      {"#FFFF00", "Yellow"}, {"#FFA500", "Orange"}, {"#800080", "Purple"},
      {"#00FFFF", "Cyan"}, {"#FFC0CB", "Pink"}, {"#808080", "Gray"},
      {"#000000", "Black"}, {"#FFFFFF", "White"}, {"#A52A2A", "Brown"},
      {"#008000", "Dark Green"}
    };
    int length = sizeof(colors) / sizeof(colors[0]);

    printf("Check Indices:\n");
    for (int j = 0; j < length; j++) {
        printf("%d --- %s\n", hash(colors[j]), colors[j].name);
    }
    printf("\n");

    for (int i = 0; i < length; i++) {
        insert(L, colors[i]);
    }

}

int get_NumOfBits(int x) {
    unsigned int mask = 1 << (sizeof(int) * 8 - 1);
    int num = 0;

    while (mask != 0) {
        mask >>= 1;
        if (mask & x) num++;
    }

    return num;
}

int get_SumOfLetters(char *key) {
    int length = strlen(key);
    int sum;

    for (int i = 0; i < length; i++) {
        sum += key[i];
    }

    return sum;
}

unsigned int hash(Color data) {
    return (get_NumOfBits(get_SumOfLetters(data.name)) * get_SumOfLetters(data.hex) + 31) % MAX;
}

void insert(ColorPtr L[], Color data) {
    int nDx = hash(data);

    ColorPtr temp = createNode(data);
    
    if (L[nDx] != NULL) {
        temp->next = L[nDx];
        L[nDx] = temp;
    } else
        L[nDx] = temp;

}


void display(ColorPtr L[]) {
    ColorPtr temp;
    int i;

    printf("Table:\n");
    printf("\t%-10s%s\n", "nDx", "Link");
    for (i = 0; i < MAX; i++) {
        printf("\t%2d", i);
        if (L[i] != NULL) {
            printf("%13s", "[LINK]");
            temp = L[i];
            while (temp != NULL) {
                printf(" -> [%-8s%s]", temp->hex, temp->name);
                temp = temp->next;
            }
        } else
            printf("%13s", "[NULL]");
        printf("\n");
    }
}