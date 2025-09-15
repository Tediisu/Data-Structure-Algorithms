#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define MAX 5

typedef struct 
{
    int hours;
    int minutes;
} Time;

typedef struct
{
    int id;
    char origin[50];
    char destination[50];
    Time departure_time;
    Time arrival_time;
} Flight;

typedef struct 
{
    Flight *flights;
    int count;
    int max;
} Flights;

void init(Flights *F);
Flight createFlight();
void addFlight(Flights *flightlist, Flight f);
Flight removedFlights(Flights *flightlist, int flightid);
void showFlights(Flights flight_list); // All flight
void displayFlightInfo(Flight flight); //Single Flight
void displayTime(Time t);
Time createTime(int h, int m);


#endif