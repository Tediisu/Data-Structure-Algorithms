#include <stdio.h>
#include "functions.c"

int main(void)
{
    List myList;

    init(&myList);
    display(myList);
    visualize(myList);

    push(&myList, 1);
    display(myList);
    visualize(myList);

    push(&myList, 2);
    display(myList);
    visualize(myList);

    push(&myList, 3);
    display(myList);
    visualize(myList);

    push(&myList, 4);
    display(myList);
    visualize(myList);

    push(&myList, 5);
    display(myList);
    visualize(myList);

    push(&myList, 6);
    display(myList);
    visualize(myList);

    return 0;
}