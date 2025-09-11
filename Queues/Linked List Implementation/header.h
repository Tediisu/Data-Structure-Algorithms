#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct Node
{
    int data;
    struct Node *next;
} Node, *NodePtr;

typedef struct
{
    NodePtr front;
    NodePtr rear;
} Queue;

void init(Queue*);
bool enQueue(Queue*, int);
bool deQueue(Queue*);
int front(Queue);
bool isEmpty(Queue);
void display(Queue);

#endif