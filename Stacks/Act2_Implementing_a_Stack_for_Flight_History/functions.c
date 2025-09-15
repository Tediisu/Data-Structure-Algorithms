#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

void initStack(FlightStack *s)
{
    s->top = -1;
}

int isStackEmpty(FlightStack *s)
{
    return (s->top == -1) ? 1 : 0;
}

int isStackFull(FlightStack *s)
{
    return ((s->top) + 1 == STACK_SIZE) ? 1 : 0;
} 

bool isEmpty(FlightStack s)
{
    return (s.top == -1);
}
bool isFull(FlightStack s)
{
    return ((s.top) + 1 == STACK_SIZE);
}
void pushFlight(FlightStack *s, Flight f)
{
    if(isFull(*s)) return;
    s->stack[++(s->top)] = f;
    printf("Flight Added!\n");
    displayFlightInfo(f);
}

Flight popFlight(FlightStack *s)
{
    Flight temp;
    temp.id = -1;

    if (isEmpty(*s)) return temp;
    temp = s->stack[s->top];
    (s->top)--;
    printf("FLight Removed!\n");
    return temp;
}
Flight peekFlight(FlightStack s)
{
    Flight temp;
    temp.id = -1;

    if (isEmpty(s)) return temp;
    temp = s.stack[s.top];
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