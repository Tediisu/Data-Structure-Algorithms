#include <stdio.h>
#include "functions.c"

int main(void)
{
    NodePtr head;

    init(&head);

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    visualize(head);

    return 0;
}