#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

void initQueue(FlightQueue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int isQueueEmpty(FlightQueue q)
{
    return (q.front == NULL) ? 1  : 0;
}

void enqueueFlight(FlightQueue *q, Flight f)
{
    Node *temp = malloc(sizeof(Node));
    if (!temp) return;
    temp->data = f;
    temp->next = NULL;

    if (q->front == NULL)
        q->front = temp;
    else
        q->rear->next = temp;

    q->rear = temp;

    printf("Flight Added!\n");
    displayFlightInfo(f);    
}
Flight dequeueFlight(FlightQueue *q)
{   
    Node *delete;
    Flight temp;
    temp.id = -1;

    if (isQueueEmpty(*q)) return temp;
    if (q->front != NULL)
    {
        temp = q->front->data;
        delete = q->front;
        q->front = delete->next;
        free(delete);

        if (q->front == NULL) q->rear = NULL;
        return temp;
    }

    return temp;
}
Flight peekQueue(FlightQueue q)
{
    Flight temp;
    temp.id = -1;

    if (q.front != NULL)
    {
        temp = q.front->data;
        return temp;
    }

    return temp;
}
void displayFlightInfo(Flight flight) 
{
    printf("=========================\n");
    printf("Flight ID: %d\n", flight.id);
    printf("Origin: %s\n", flight.origin);
    printf("Destination: %s\n", flight.destination);
    printf("Departure Time: ");
    displayTime(flight.departure_time);
    printf("\n");
    printf("Arrival Time: ");
    displayTime(flight.arrival_time);
    printf("\n");
    printf("=========================\n\n");
}

void displayTime(Time t)
{
    char prefix[] = "AM";
    if (t.hours > 12)
    {
        t.hours -= 12;
        prefix[0] = 'P';
        prefix[1] = 'M';
    }
    printf("%02d:%02d %s", t.hours, t.minutes, prefix);
}
