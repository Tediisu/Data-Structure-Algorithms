#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef enum {false, true} Bool;
typedef Bool SETS[MAX];

void initSets(SETS *S);
Bool isMember(SETS S, int data);
void insert(SETS *S, int data);
void unionOfSets(SETS *A, SETS *B, SETS *U);
void intersect(SETS *A, SETS *B, SETS *I);
void difference(SETS *A, SETS *B, SETS *D);
void asymetricDifference(SETS *A, SETS *B, SETS *AD);
void merge(SETS *A, SETS *B);
void assign(SETS *A, SETS *B);
Bool equal(SETS *A, SETS *B);
Bool find(SETS *A, int data);
void delete(SETS *A, int data);
void populateA(SETS *S);
void populateB(SETS *S);
void display(SETS S);

int main(void)
{
  SETS A;
  SETS B;
  SETS U;
  SETS I;
  SETS D;
  SETS AD;

  initSets(&A);
  initSets(&B);
  initSets(&U);
  initSets(&I);
  initSets(&D);
  initSets(&AD);
  populateA(&A);
  populateB(&B);
  unionOfSets(&A, &B, &U);
  intersect(&A, &B, &I);
  difference(&A, &B, &D);
  asymetricDifference(&A, &B, &AD);


  display(A);
  display(B);
  printf("\nUnion: ");
  display(U);
  printf("\nIntersection: ");
  display(I);
  printf("\nDifference: ");
  display(D);
  printf("\nAsymmetric Difference: ");
  display(AD);

  return 0;
}

void initSets(SETS *S)
{
  int i;
  for (i = 0; i < MAX; i++)
  {
    (*S)[i] = false;
  }
}

Bool isMember(SETS S, int data)
{
  return (S[data] == true) ? true : false;
}

void insert(SETS *S, int data)
{
  if (isMember(*S, data) == false)
  {
    (*S)[data] = true;
  }
}

void unionOfSets(SETS *A, SETS *B, SETS *U)
{
  int i;

  for (i = 0; i < MAX; i++)
  {
    if ((*A)[i] == true || (*B)[i] == true)
    {
      (*U)[i] = true;
    }
  }
}

void intersect(SETS *A, SETS *B, SETS *I)
{
  int i;
  for (i = 0; i < MAX; i++)
  {
    if ((*A)[i] == true && (*B)[i] == true)
    {
      (*I)[i] = true;
    }
  }
}

void difference(SETS *A, SETS *B, SETS *D)
{
  int i;
  for (i = 0; i < MAX; i++)
  {
    if ((*A)[i] == true && (*B)[i] == false)
    {
      (*D)[i] = true;
    }
  }
}

void asymetricDifference(SETS *A, SETS *B, SETS *AD)
{
  int i;
  for (i = 0; i < MAX; i++)
  {
    if ((*A)[i] != (*B)[i])
    {
      (*AD)[i] = true;
    }
  }
}

void merge(SETS *A, SETS *B)
{
  int i;
  Bool flag = true;

  for (i = 0; i < MAX; i++)
  {
    if ((*A)[i] && (*B)[i])
    {
        flag = false;
        break;
    }
  }

  if (flag)
  {
    for (i = 0; i < MAX; i++)
    {
      if ((*B)[i])
      {
        (*A)[i] = true;
      }
    }
  }

}

void assign(SETS *A, SETS *B)
{
  int i;

  for (i = 0; i < MAX; i++)
  {
      (*A)[i] = (*B)[i];
  }
}

Bool equal(SETS *A, SETS *B)
{
  int i;

  for (i = 0; i < MAX; i++)
  {
    if ((*A)[i] != (*B)[i])
      return false;
  }

  return true;
}

Bool find(SETS *A, int data)
{
  return ((*A)[data] == true) ? true : false;
}

void delete(SETS *A, int data)
{
  (*A)[data] = false;
}

void populateA(SETS *S)
{
  int arr[] = {9, 21, 25, 29, 33, 34, 40};
  int l = sizeof(arr) / sizeof(arr[0]);
  int i;

  for (i = 0; i < l; i++)
  {
    insert(S, arr[i]);
  }
}
void populateB(SETS *S)
{
  int arr[] = {2, 21, 13, 25, 33, 29, 47};
  int l = sizeof(arr) / sizeof(arr[0]);
  int i;

  for (i = 0; i < l; i++)
  {
    insert(S, arr[i]);
  }
}
void display(SETS S)
{
  int i;

  printf("List {");
  for (i = 0; i < MAX; i++)
  {
    if (S[i] == true ) printf("%d ", i);
  }
  printf("}\n");
}
