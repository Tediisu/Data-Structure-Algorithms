#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

void init(NodePtr *head)
{
    *head = NULL;
}

bool push(NodePtr *head, int x)
{
    NodePtr temp = malloc(sizeof(Node));
    if (!temp) return false;
    temp->data = x;
    temp->next = *head;
    *head = temp;

    return true;
}

bool pop(NodePtr *head)
{
    NodePtr temp;

    if (isEmpty(*head)) return false;
    temp = *head;
    *head = temp->next;
    free(temp);
}

int peek(NodePtr head)
{
    return head->data;
}
bool isEmpty(NodePtr head)
{
    return (head == NULL);
}

void visualize(NodePtr head)
{
    bool top = true;

    printf("%10s", "Visualization:\n\n");
    if (!isEmpty(head))
    {
        printf("+-------+\n");
        printf("| Data  |\n");
        printf("+-------+\n");
        for (; head != NULL; head = head->next)
        {
            printf("|   %d   |", head->data);
            if (top)
            {
                printf(" <- Top");
                top = false;
            }
            printf("\n");
        }
        printf("+-------+\n");
    }
    else
        printf("\tList is empty!");
}