#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 6

typedef struct 
{
    int A[MAX];
    int front;
    int rear;
} Queue;

void initQ(Queue *Q);
bool isFull(Queue Q);
bool isEmpty(Queue Q);
bool enQueue(Queue *Q, int data);
bool enQueueSorted(Queue *Q, int data);
bool deQueue(Queue *Q);
void display(Queue Q);
void visualize(Queue Q);


int main(void)
{
    Queue Q;
    int i;

    initQ(&Q);
    enQueueSorted(&Q, 2);
    enQueueSorted(&Q, 5);
    enQueueSorted(&Q, 1);
    enQueueSorted(&Q, 7);
    enQueueSorted(&Q, 10);

    // enQueue(&Q, 10);

    visualize(Q);

    return 0;
}

void initQ(Queue *Q)
{
    Q->front = 0;
    Q->rear = MAX - 1;
}
bool isFull(Queue Q)
{
    return (Q.rear + 2) % MAX == Q.front;
}
bool isEmpty(Queue Q)
{
    return (Q.rear + 1) % MAX == Q.front;
}
bool enQueue(Queue *Q, int data)
{
    if (isFull(*Q)) return false;

    Q->rear = (Q->rear + 1) % MAX;
    Q->A[Q->rear] = data;

    return true;
}
bool enQueueSorted(Queue *Q, int data)
{
    Queue tempQ = {.front = 0, .rear = MAX - 1};
    
    while (Q->front != (Q->rear + 1) % MAX && Q->A[Q->front] < data)
    {
        tempQ.rear = (tempQ.rear + 1) % MAX;
        tempQ.A[tempQ.rear] = Q->A[Q->front];
        Q->front = (Q->front + 1) % MAX;
    }

    tempQ.rear = (tempQ.rear + 1) % MAX;
    tempQ.A[tempQ.rear] = data;

    while (Q->front != (Q->rear + 1) % MAX)
    {
        tempQ.rear = (tempQ.rear + 1) % MAX;
        tempQ.A[tempQ.rear] = Q->A[Q->front];
        Q->front = (Q->front + 1) % MAX;
    }

    *Q = tempQ;
}
bool deQueue(Queue *Q)
{
    if (isEmpty(*Q)) return false;

    Q->front = (Q->front + 1) % MAX;
    return true;
}
void display(Queue Q);
void visualize(Queue Q)
{
    int i = Q.front;

    while(i != (Q.rear + 1) % MAX) 
    {
        printf("%d ", Q.A[i]);
        i = (i + 1) % MAX;
    }
}