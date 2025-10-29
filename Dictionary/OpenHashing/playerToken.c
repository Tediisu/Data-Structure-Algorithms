#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node{
    int tokenID;         // Unique ID of the token
    char playerName[32]; // Name of the player who owns it
    int credits;         // Remaining credits
    struct Node *next;
  } Token, *TokenPtr;

typedef TokenPtr Dictionary[MAX];

void initDic(Dictionary D);
int total_OfBits(int x);
int total_numOfLetters(char *key);
unsigned int hash(Token data);
void insert(Dictionary D, Token data);
void findToken(Dictionary D, Token data);
void deleteToken(Dictionary D, Token data);
void populate(Dictionary D);
void clearDictionary(Dictionary D);
void display(Dictionary D);

int main(void) {
  Token p1 = {1001, "Alice", 50};
  Token p2 = {1005, "Ethan", 60};
  Dictionary B;

  initDic(B);
  populate(B);

  display(B);

  findToken(B, p1);
  findToken(B, p2);
  deleteToken(B, p2);
  deleteToken(B, p1);

  display(B);
  clearDictionary(B);
  display(B);

  return 0;
}

void initDic(Dictionary D) {
  for (int i = 0; i < MAX; i++) {
    D[i] = NULL;
  }

}

int total_OfBits(int x) {
  unsigned int mask = 1 << (sizeof(int) * 8 - 1);
  int total = 0;

  while (mask != 0) {
    if (mask & x) total++;
    mask >>= 1;
  }

  return total;
}

int total_numOfLetters(char *key) {
  int length = strlen(key);
  int total = 0;

  for (int i = 0; i < length; i++) {
    total += key[i];
  }

  return total;
}

unsigned int hash(Token data) {
  return (total_OfBits(total_numOfLetters(data.playerName))  * data.tokenID + 31) % MAX;
}

void populate(Dictionary D) {
  Token tokens[12] = {{1001, "Alice", 50}, {1002, "Bob", 75}, {1003, "Charlie", 20},
                      {1004, "Diana", 100}, {1005, "Ethan", 60}, {1006, "Fiona", 85},
                      {1007, "George", 45}, {1008, "Hannah", 90}, {1009, "Ian", 35},
                      {1010, "Jasmine", 70}, {1011, "Kyle", 55}, {1012, "Luna", 95}
                      };
  int length = sizeof(tokens) / sizeof(tokens[0]);

  for (int i = 0; i < length; i++) {
    insert(D, tokens[i]);
  }
}

void insert(Dictionary D, Token data) {
  TokenPtr temp;
  int nDx = hash(data);
  printf("%d\n", nDx);

  temp = malloc(sizeof(Token));
  if (!temp) return;

  temp->tokenID = data.tokenID;
  strcpy(temp->playerName, data.playerName);
  temp->credits = data.credits;
  temp->next = D[nDx];
  D[nDx] = temp;

}

void findToken(Dictionary D, Token data) {
  int nDx = hash(data);
  TokenPtr temp = D[nDx];

  while (temp != NULL && data.tokenID != temp->tokenID) {
    temp = temp->next;
  }

  printf("\n\nToken ID found [%d]: %-5d%-7s%d", data.tokenID, temp->tokenID, temp->playerName, temp->credits);

}

void deleteToken(Dictionary D, Token data) {
  int nDx = hash(data);
  TokenPtr *trav, temp;

  if (!D[nDx]) return;
  for (trav = &D[nDx]; *trav != NULL && (*trav)->tokenID != data.tokenID; trav = &(*trav)->next){}
  temp = *trav;
  *trav = temp->next;
  free(temp);

}

void clearDictionary(Dictionary D) {
  TokenPtr *trav, temp;
  int i;

  /*
  for (i = 0; i < MAX; i++) {
    trav = &D[i];
    while (*trav != NULL) {
      if (*trav == NULL) return;
      temp = *trav;
      trav = &(*trav)->next;
      free(temp);
    }
    D[i] = NULL;
  }
  */

   for (i = 0; i < MAX; i++) {
    temp = D[i];
    while (temp != NULL) {
      free(temp);
      temp = temp->next;
    }
    D[i] = NULL;
  }

}

void display(Dictionary D) {
  printf("\nTable:\n");
  printf("\t%-10s%s\n", "nDx", "Link");
  for (int i = 0; i < MAX; i++) {
    printf("\t%2d", i);
    if (D[i] != NULL) {
      printf("%12s", "Link");
      TokenPtr temp = D[i];
      for (; temp != NULL; temp = temp->next) {
        printf("  -->[%-5d%-7s%d] ", temp->tokenID, temp->playerName, temp->credits);
      }
    } else
      printf("%12s", "NULL");
    printf("\n");
  }

}

