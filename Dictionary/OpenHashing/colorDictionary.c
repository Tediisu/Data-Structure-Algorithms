#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    char hex[32];
    char name [32];
    struct Node *next;
} Color, *ColorPtr;

typedef ColorPtr Dictionary[MAX];

void initDictionary(Dictionary D);
void populate(Dictionary D);
int get_SumOfBits(int x);
int get_SumOfLetters(char *key);
unsigned int hash(Color data);
ColorPtr createNode(Color data);
void insert(Dictionary D, Color data);
ColorPtr search(Dictionary D, Color data);
ColorPtr delete(Dictionary D, Color data);
void display(Dictionary D);

int main(void) {
    Color temp = {"#FF0000", "Red"};
    Dictionary D;

    initDictionary(D);
    populate(D);
    display(D);
    
    ColorPtr getColor = search(D, temp);
    if (getColor != NULL) {
        printf("%s, %s", getColor->hex, getColor->name);
    } else
        printf("\n\nThere's no Color %s", temp.name);

    return 0;
}

void initDictionary(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i] = NULL;
    }

}

void populate(Dictionary D) {
    Color colors[13] = {
      {"#FF0000", "Red"}, {"#00FF00", "Green"}, {"#0000FF", "Blue"},
      {"#FFFF00", "Yellow"}, {"#FFA500", "Orange"}, {"#800080", "Purple"},
      {"#00FFFF", "Cyan"}, {"#FFC0CB", "Pink"}, {"#808080", "Gray"},
      {"#000000", "Black"}, {"#FFFFFF", "White"}, {"#A52A2A", "Brown"},
      {"#008000", "Dark Green"}
    };
    int length = sizeof(colors) / sizeof(colors[0]);

    for (int i = 0; i < length; i++) {
        printf("%d\n", hash(colors[i]));
        insert(D, colors[i]);
    }
    // insert(D, colors[0]);

}

int get_SumOfBits(int x) {
    unsigned int mask = 1 << (sizeof(int) * 8 - 1);
    int sum = 0;

    while (mask != 0) {
        if (mask & x) sum++;
        mask >>= 1;
    }

    return sum;
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
    return (get_SumOfBits(get_SumOfLetters(data.hex) * get_SumOfLetters(data.name) + 31)) % MAX;
}

ColorPtr createNode(Color data) {
    ColorPtr temp = malloc(sizeof(Color));
    if (!temp) return NULL;
    strcpy(temp->hex, data.hex);
    strcpy(temp->name, data.name);
    temp->next = NULL;

    return temp;
}

void insert(Dictionary D, Color data) {
    int nDx = hash(data);
    ColorPtr temp = createNode(data);

    if (D[nDx] != NULL) {
        temp->next = D[nDx];
        D[nDx] = temp;
    } else
        D[nDx] = temp;
    
}

ColorPtr search(Dictionary D, Color data) {
    int nDx = hash(data);
    ColorPtr temp;

    if (D[nDx] != NULL) {
        for (temp = D[nDx]; temp != NULL && strcmp(temp->hex, data.hex) != 0; temp = temp->next){}
        return temp;
    }

    return NULL;
}

ColorPtr delete(Dictionary D, Color data) {
    int nDx = hash(data);
    ColorPtr temp;

    if (D[nDx] != NULL) {
        for (temp = D[nDx]; temp != NULL && strcmp(temp->hex, data.hex) != 0; temp = temp->next){}
        return temp;
    }

    return NULL;
}

void display(Dictionary D) {
    printf("Table:\n");
    printf("\t%-10s%s\n", "nDx", "Type");
    for (int i = 0; i < MAX; i++) {
        printf("\t%2d", i);
        if (D[i] != NULL) {
            printf("%13s", "[LINK]");
            
            ColorPtr temp = D[i];
            
            while (temp != NULL) {
                printf(" -> [%-10s%s]", temp->hex, temp->name);
                temp = temp->next;
            }
        } else 
            printf("%13s", "[NULL]");

        printf("\n");
    }

} 