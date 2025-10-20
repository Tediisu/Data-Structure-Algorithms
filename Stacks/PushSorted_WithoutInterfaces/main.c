#include <stdio.h>
#include "functions.c"

int main(void)
{
    Stack myStack;
    
    initStack(&myStack);
    pushSorted(&myStack, 7);
    pushSorted(&myStack, 5);
    pushSorted(&myStack, 1);
    pushSorted(&myStack, 6);

    display(myStack);

    return 0;
}