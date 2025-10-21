  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <string.h>
  #include <conio.h>

  #define MAX 20

  typedef struct {
    char hex[32];
    char name[32];
  } Color, *ColorPtr;


  void initList(ColorPtr *L);
  void simulateCollision(ColorPtr L, Color data, int nDx);
  int getNumOfBits(int val);
  int sumOfLetters(char *key);
  unsigned int hash(Color data); // key
  void insert(ColorPtr *L, Color data);
  void delete(ColorPtr *L, Color data);
  void update(ColorPtr *L, Color data, Color data2);
  void displayTable(ColorPtr L);
  void pause();

  int main(void) {
    Color colors[13] = {
      {"#FF0000", "Red"}, {"#00FF00", "Green"}, {"#0000FF", "Blue"},
      {"#FFFF00", "Yellow"}, {"#FFA500", "Orange"}, {"#800080", "Purple"},
      {"#00FFFF", "Cyan"}, {"#FFC0CB", "Pink"}, {"#808080", "Gray"},
      {"#000000", "Black"}, {"#FFFFFF", "White"}, {"#A52A2A", "Brown"},
      {"#008000", "Dark Green"}
    };
    Color temp = {"#FKJ300", "Yoshimitsu"};
    ColorPtr myList;
    int i;

    initList(&myList);
    displayTable(myList);
    pause();
    for (i = 0; i < 13; i++) {
      insert(&myList, colors[i]);
    }
    displayTable(myList);
    pause();
    delete(&myList, colors[10]);
    displayTable(myList);
    pause();
    update(&myList, colors[11], temp);
    displayTable(myList);
    pause();

    return 0;
  }

  void initList(ColorPtr *L) {
    *L = malloc(sizeof(Color) * MAX);
    if (*L == NULL) return;

    for (int i = 0; i < MAX; i++) {
      strcpy((*L)[i].hex, "");
      strcpy((*L)[i].name, "");
    }
  }

  int getNumOfBits(int val) {
    return __builtin_popcount(val);
  }

  int sumOfLetters(char *key) {
    int length = strlen(key);
    int total = 0;

    for (int i = 0; i < length; i++) {
      total += key[i];
    }

    return total;
  }

  unsigned int hash(Color data) { // key
    // unsigned int hashBrown = (getNumOfBits(sumOfLetters(data.hex)) * sumOfLetters(data.name) + 32) % MAX;
    return (getNumOfBits(sumOfLetters(data.hex)) * sumOfLetters(data.name) + 32) % MAX;
  }

  void simulateCollision(ColorPtr L, Color data, int nDx) {
    int i;

    printf("\t========== Collision Detected ==========\n");
    printf("Table:\n");
    printf("\t%s%10s%15s\n", "Index", "Hex", "Color");
    for (i = 0; i < MAX; i++) {
      printf("\t%3d", i);
      if (strcmp(L[i].hex, "") != 0) {
        printf("\t%10s%12s", L[i].hex, L[i].name);
        if (i == nDx && strcmp(L[i].hex, "") != 0) {
          printf("   >===<%10s%12s", data.hex, data.name);
        }
        printf("\n");
      } else {
        printf("%12s%14s\n", "---", "---");
      }
        printf("\n");
    }
  }

  void insert(ColorPtr *L, Color data) {
    int nDx = hash(data);
    int flag = nDx;

    // if (strcmp((*L)[nDx].hex, "") != 0) {
    //   printf("Data %s %s at %d will be replaced.\n", (*L)[nDx].hex, (*L)[nDx].name, nDx);
    //   (*L)[nDx] = data;
    //   printf("Data %s %s inserted at %d.\n", (*L)[nDx].hex, (*L)[nDx].name, nDx);
    // } else
    //   (*L)[nDx] = data;

    while (strcmp((*L)[nDx].hex, "") != 0) {
      simulateCollision(*L, data, nDx);
      nDx = (nDx + 1) % MAX;
      pause();
      if (nDx == flag) return;
    }
    (*L)[nDx] = data;

  }

  void delete(ColorPtr *L, Color data) {
    unsigned int nDx = hash(data);
    int flag = nDx;

    while (strcmp((*L)[nDx].hex, data.hex) != 0) {
      nDx = (nDx + 1) % MAX;
      if (nDx == flag) return;
    }
    strcpy((*L)[nDx].hex, "");
    strcpy((*L)[nDx].name, "");

  }

  void update(ColorPtr *L, Color data, Color data2) {
    unsigned int nDx = hash(data);
    int flag = nDx;

    while (strcmp((*L)[nDx].hex, data.hex) != 0) {
      nDx = (nDx + 1) % MAX;
      if (nDx == flag) return;
    }
    strcpy((*L)[nDx].hex, data2.hex);
    strcpy((*L)[nDx].name, data2.name);

  }

  void displayTable(ColorPtr L) {
    int i;

    printf("Table:\n");
    printf("\t%s%10s%15s\n", "Index", "Hex", "Color");
    for (i = 0; i < MAX; i++) {
      printf("\t%3d", i);
      if (strcmp(L[i].hex, "") != 0) {
        printf("\t%10s%12s\n", L[i].hex, L[i].name);
      } else {
        printf("%12s%14s\n", "---", "---");
      }
        printf("\n");
    }
  }

  void pause(void) {
      printf("\n\nPress any key to continue...");
      _getch();
      system("CLS");
  }
