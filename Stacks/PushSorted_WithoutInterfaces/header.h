#ifndef HEADER_H_INCLCUDED
#define HEADER_H_INCLUDED

typedef struct Node 
{
    int data;
    struct Node *add;
} Node, *NodePtr, *Stack;

void initStack(Stack *S);
bool pushSorted(Stack *S, int val);
void display(Stack S);

#endif 