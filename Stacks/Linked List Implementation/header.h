#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct Node 
{
    int data;
    struct Node *next;
} Node, *NodePtr;

void init(NodePtr*);
bool push(NodePtr*, int);
bool pop(NodePtr*);
int peek(NodePtr);
bool isEmpty(NodePtr);
void visualize(NodePtr);

#endif