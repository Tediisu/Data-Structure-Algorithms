#include <stdio.h>
#include "functions.c"

int main(void)
{
    Flight tempFlights[] = {1, "Alaska", "New York", {10, 00}, {14, 30},
                            2, "New York", "Alaska", {12, 30}, {16, 00},
                            3, "Japan", "Singapore", {14, 30}, {18, 00},
                            4, "Philippines", "New Zealand", {16, 00}, {20, 30},
                            5, "Germany", "Japan", {18, 00}, {22, 30},
                            6, "New York", "Singapore", {20, 30}, {24, 00},
                            7, "Austrilia", "New Zealand", {22, 30}, {26, 00},
                            8, "China", "New Zealand", {24, 30}, {28, 00}
                            };
    FlightQueue Q;
    int i;

    initQueue(&Q);
    for (i = 0; i < 8; i++)
    {
        enqueueFlight(&Q, tempFlights[i]);
    }
    
    Flight deQd = dequeueFlight(&Q);
    printf("Dequeued Flight!\n");
    displayFlightInfo(deQd);

    Flight top = peekQueue(Q);
    printf("Current Flight!\n");
    displayFlightInfo(top);

    return 0;
}