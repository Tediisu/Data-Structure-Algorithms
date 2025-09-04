#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define MAX 5

typedef int Data;
typedef struct 
{
    int elems[MAX];
    int top;
} List;

void init(List *L);
bool push(List *L, Data item);
Data peek(List L);
bool pop(List *L);
bool isEmpty(List);
bool isFull(List);
void display(List);
void visualize(List);

#endif