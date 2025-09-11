#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

void init(Queue *head)
{
    head->front = NULL;
    head->rear = NULL;
}

bool enQueue(Queue *head, int x)
{
    NodePtr temp = malloc(sizeof(Node));
    if (!temp) return false;
    temp->data = x;
    temp->next = NULL;

    if (head->front == NULL)
    {
        head->front = temp;
    }
    else
        head->rear->next = temp;
    
    head->rear = temp;

    return true;
}
bool deQueue(Queue *head)
{
    NodePtr temp;

    if (isEmpty(*head)) return false;
    if (head->front != NULL)
    {
        temp = head->front;
        head->front = temp->next;
        free(temp);

        if (head->front == NULL) head->rear = NULL;
    }

    return true;
}
int front(Queue head)
{
    int num = -1;

    if (!   isEmpty(head))
    {
        num = head.front->data;
    }

    return num;
}
bool isEmpty(Queue head)
{
    return (head.front == NULL);
}

void display(Queue head)
{
    for (; head.front != NULL; head.front = head.front->next)
    {
        printf("%d", head.front->data);
        if (head.front->next != NULL) printf(" -> ");
    }
    printf("\n\n");
}
// void display(Queue head)
// {
//     for(;head.front != NULL; head.front = head.front->next){
//         printf("%d->", head.front->data);
//     }
//     printf("\n\n");
// }