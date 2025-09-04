#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

void init(List *L)
{
    L->top = -1;
}

bool push(List *L, Data item)
{
    if (isFull(*L)) return false;
    L->elems[++(L->top)] = item;

    return true;
}

Data peek(List L)
{
    return L.elems[L.top];
}

bool pop(List *L)
{
    if (isEmpty(*L)) return false;
    (L->top)--;
    return true;
}

bool isEmpty(List L)
{
    return (L.top == -1);
}

bool isFull(List L)
{
    return (L.top == MAX - 1);
}

void display(List L)
{
    printf("Display { ");
    if (L.top != -1) 
    {
        while (!isEmpty(L))
        {
            printf("%d ", peek(L));
            if (L.top != 0) printf(", ");
            pop(&L);
        }   
    }  
    else
    {
        printf("List is Empty! }\n");
        return;
    }
    printf("}\n");
}

void visualize(List L)
{
    int i;
    
    printf("\nVisualization:\n\n");
    if (L.top != -1) 
    {
        printf("\t Index    Data \n\n\n");
        for (i = L.top; i >= 0; i--)
        {
            printf("\t|   %d   |   %d   |", i, L.elems[i]);
            if (i == L.top)printf("<- Top");
            printf("\n");
        }
        printf("\t=================\n\n");
    }
    else
    {
        printf("\tList is Empty!\n\n");
    }
    
    return;
}