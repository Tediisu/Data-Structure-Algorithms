#include <stdio.h>
#include "functions.c"

int main(void)
{
    Queue A;

    init(&A);
    enQueue(&A, 1);
    enQueue(&A, 2);
    enQueue(&A, 3);
    enQueue(&A, 4);
    enQueue(&A, 5);

    display(A);
    deQueue(&A);
    display(A);


    return 0;
}