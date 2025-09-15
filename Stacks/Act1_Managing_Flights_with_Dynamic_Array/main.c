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
    Flights flightDetails;
    int i;

    init(&flightDetails);
    for (i = 0; i < 5; i++)
    {
        addFlight(&flightDetails, tempFlights[i]);
    }

    showFlights(flightDetails);
    displayFlightInfo(flightDetails.flights[1]);

    return 0;
}