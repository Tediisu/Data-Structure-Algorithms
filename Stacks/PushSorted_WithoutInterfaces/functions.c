#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

void initStack(Stack *S)
{
    *S = NULL;
}

bool pushSorted(Stack *S, int val)
{
    NodePtr temp, tempHolder;
    Stack tempStack = NULL;

    temp = malloc(sizeof(Node));
    if (!temp) return false;
    temp->data = val;

    if (*S == NULL)
    {
        temp->add = NULL;
        *S = temp;
        return true;
    }

    while (*S != NULL)
    {
        if ((*S)->data < val)
        {
            tempHolder = *S;
            *S = tempHolder->add;
            tempHolder->add = tempStack;
            tempStack = tempHolder;
        }
        else
            break;
    }

    temp->add = *S;
    *S = temp;

    while (tempStack != NULL)
    {
        tempHolder = tempStack;
        tempStack = tempStack->add;
        tempHolder->add = *S;
        *S = tempHolder;
    }

    return true;
}

void display(Stack S)
{
    printf("Head -> ");
    for (; S != NULL; S = S->add)
    {
        printf("%d", S->data);
        if (S->add != NULL) printf(" -> ");
    }
}