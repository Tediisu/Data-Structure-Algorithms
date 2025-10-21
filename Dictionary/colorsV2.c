  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <string.h>
  #include <conio.h>
  #include <windows.h>

  #define MAX 20

  typedef struct {
    char hex[32];
    char name[32];
  } Color, *ColorPtr;

void initList(ColorPtr *CL);
int get_SumOfBits(int key);
int get_SumOfLetters(char *key);
unsigned int hash(Color data);
void insert(ColorPtr *CL, Color data);
void  update(ColorPtr *CL, Color data, Color xData);
void delete(ColorPtr *CL, Color data);
void populate(ColorPtr *CL);
void visualize(ColorPtr *CL, Color data, int nDx);
void display(ColorPtr CL);
void pause();

int main(void) {
  Color white = {"#FFFFFF", "White"};
  Color brown = {"#A52A2A", "Brown"};
  Color black = {"#000000", "Black"};
  Color change = {"#X10A120", "Yoshimitsu"};
  ColorPtr cList;

  initList(&cList);
  populate(&cList);
  display(cList);
  pause();
  printf("Delete Section:\n");
  delete(&cList, white);
  display(cList);
  delete(&cList, brown);
  display(cList);
  pause();
  printf("Update Section:\n");
  update(&cList, black, change);
  display(cList);
  pause();

    return 0;
  }

void initList(ColorPtr *CL) {
  *CL = malloc(sizeof(Color) * MAX);
  if (!CL) return;
  for (int i = 0; i < MAX; i++) {
    strcpy((*CL)[i].hex, "");
    strcpy((*CL)[i].name, "");
  }

}

int get_SumOfBits(int key) {
  unsigned int mask = 1 << (sizeof(int) * 8 - 1);
  int sum = 0;

  for (; mask != 0; mask >>= 1) {
    if(mask & key) sum++;
  }

  return sum;
}

int get_SumOfLetters(char *key) {
  int length = strlen(key);
  int total = 0;

  for (int i = 0; i < length; i++) {
    total += key[i];
  }

  return total;
}

unsigned int hash(Color data) {
  return (get_SumOfBits(get_SumOfLetters(data.hex)) * get_SumOfLetters(data.name) + 32) % MAX;
}

void insert(ColorPtr *CL, Color data) {
  int getnDx = hash(data);
  int flag = getnDx;

  visualize(CL, data, getnDx);
  while (strcmp((*CL)[getnDx].hex, "") != 0) {
    getnDx = (getnDx + 1) % MAX;
    visualize(CL, data, getnDx);
    display(*CL);
    if (getnDx == flag) return;
  }
  (*CL)[getnDx] = data;
  display(*CL);

}

void  update(ColorPtr *CL, Color data, Color xData) {
  int getnDx = hash(data);
  int flag = getnDx;

  visualize(CL, data, getnDx);
  while (strcmp((*CL)[getnDx].hex, data.hex) != 0) {
    getnDx = (getnDx + 1) % MAX;
    visualize(CL, data, getnDx);
    display(*CL);
    if (getnDx == flag) return;
  }
  strcpy((*CL)[getnDx].name, xData.name);
  strcpy((*CL)[getnDx].hex, xData.hex);
  display(*CL);

}

void delete(ColorPtr *CL, Color data) {
  int getnDx = hash(data);
  int flag = getnDx;

  visualize(CL, data, getnDx);
  while (strcmp((*CL)[getnDx].hex, data.hex) != 0) {
    getnDx = (getnDx + 1) % MAX;
    visualize(CL, data, getnDx);
    display(*CL);
    if (getnDx == flag) return;
  }
  strcpy((*CL)[getnDx].hex, "");
  strcpy((*CL)[getnDx].name, "");
  display(*CL);

}

void populate(ColorPtr *CL) {
    Color colors[13] = {
      {"#FF0000", "Red"}, {"#00FF00", "Green"}, {"#0000FF", "Blue"},
      {"#FFFF00", "Yellow"}, {"#FFA500", "Orange"}, {"#800080", "Purple"},
      {"#00FFFF", "Cyan"}, {"#FFC0CB", "Pink"}, {"#808080", "Gray"},
      {"#000000", "Black"}, {"#FFFFFF", "White"}, {"#A52A2A", "Brown"},
      {"#008000", "Dark Green"}
    };
    int length = sizeof(colors) / sizeof(colors[0]);

    for (int i = 0; i < length; i++) {
      insert(CL, colors[i]);
    }

}

void visualize(ColorPtr *CL, Color data, int nDx) {
  Sleep(1500);
  system("CLS");
  printf("Table:\n");
  printf("\t%s%12s%18s\n", "nDx", "Hex", "Name");
  for (int i = 0; i < MAX; i++) {
    printf("\t%2d", i);
    if (strcmp((*CL)[i].hex, "") != 0) {
      printf("\t%9s%15s", (*CL)[i].hex, (*CL)[i].name);
    } else
        printf("\t%7s%17s", "---", "---");
    if (i == nDx) printf("%7s [%1s%10s]", "<|===",data.hex, data.name);
    printf("\n");
  }

}

void display(ColorPtr CL) {
  Sleep(1500);
  system("CLS");
  printf("Table:\n");
  printf("\t%s%12s%18s\n", "nDx", "Hex", "Name");
  for (int i = 0; i < MAX; i++) {
    printf("\t%2d", i);
    if (strcmp(CL[i].hex, "") != 0) {
      printf("\t%9s%15s\n", CL[i].hex, CL[i].name);
    } else
      printf("\t%7s%17s\n", "---", "---");
  }
}

void pause() {
  printf("\n\nPress any key to continue;");
  _getch();
  system("CLS");
}
