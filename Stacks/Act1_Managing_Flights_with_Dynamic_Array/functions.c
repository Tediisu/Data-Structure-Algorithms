#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"
#define MAX 5

void init(Flights *F)
{
    F->flights = malloc(sizeof(Flight) * MAX);
    F->count = 0;
    F->max = MAX;
}
Flight createFlight()
{
    Flight details;
    int h, m;

    fflush(stdin);
    printf("Enter Flight ID: ");
    scanf("%d", &details.id);
    fflush(stdin);
    printf("Enter Flight Origin: ");
    fgets(details.origin, 50, stdin);
    fflush(stdin);
    printf("Enter Flight Destination: ");
    fgets(details.destination, 50, stdin);
    fflush(stdin);
    printf("Enter Departure Time (minutes): ");
    scanf("%d", &m);
    printf("Enter Departure Time (hours): ");
    scanf("%d", &h);
    details.departure_time = createTime(h, m);
    printf("Enter Arrival Time (minutes): ");
    scanf("%d", &m);
    printf("Enter Arrival Time (hours): ");
    scanf("%d", &h);
    details.arrival_time = createTime(h, m);

    return details;
}
void addFlight(Flights *flightlist, Flight f)
{
    if (flightlist->count < flightlist->max)
    {
        flightlist->flights[(flightlist->count)++] = f;
    }
    else
    {
        flightlist->max *= 2;
        flightlist->flights = realloc(flightlist->flights, flightlist->max);
        flightlist->flights[(flightlist->count)++] = f;
    }
}
Flight removedFlights(Flights *flightlist, int flightid)
{
    Flight temp;

    int i;
    for (i = 0; i < flightlist->count && flightlist->flights[i].id != flightid; i++){}
    if (flightlist->flights[i].id == flightid)
    {
        temp.id = flightlist->flights[i].id;
        memcpy(flightlist->flights + i, &flightlist->flights + i + 1, sizeof(Flight) * (flightlist->count - i));
        (flightlist->count)--;

        return temp;
    }

    temp.id = -1;

    return temp;
}
void showFlights(Flights flight_list)
{
    int i;

    printf("%-8s %-12s %-12s %-10s %-15s %-15s\n", "TIME", "DEPARTURE", "ARRIVAL", "FLIGHT ID", "ORIGIN", "DESTINATION");

    for (i = 0; i < flight_list.count; i++)
    {
        printf("%-8s   %02d:%02d       %02d:%02d     \t%-5d %-15s %-15s\n",
               "", 
               flight_list.flights[i].departure_time.hours, flight_list.flights[i].departure_time.minutes,
               flight_list.flights[i].arrival_time.hours, flight_list.flights[i].arrival_time.minutes,
               flight_list.flights[i].id,
               flight_list.flights[i].origin,
               flight_list.flights[i].destination);
    }
    printf("\n\n");
}

void displayFlightInfo(Flight flight) //Single Flight
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
    printf("=========================\n");
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

Time createTime(int h, int m)
{
    Time time;
    time.hours = h;
    time.minutes = m;
    return time;
}