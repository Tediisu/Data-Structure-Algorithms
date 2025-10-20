✈️ Activity 1: Managing Flights with Dynamic Arrays

🧠 Learning Objectives
- Understand dynamic array structures using count and max fields.
- Implement basic CRUD operations on a dynamic array.
- Practice modular programming with structs and function interfaces.

🗂️ Structures to Define
`c
typedef struct {
    int hours;
    int minutes;
} Time;

typedef struct {
    int id;
    char origin[50];
    char destination[50];
    Time departure_time;
    Time arrival_time;
} Flight;

typedef struct {
    Flight *flights;
    int count;
    int max;
} Flights;
`

🛠️ Functions to Implement
`c
Flight createFlight(); //Use flight data as parameters
void addFlight(Flights *flight_list, Flight f);
Flight removeFlight(Flights *flightlist, int flightid); // returns Flight with id -1 if not found
void showFlights(Flights flight_list);
void displayFlightInfo(Flight f);
void display time(Time t); // display in standard time HH:MM XX
Time createTime(int h, int m);
`

📋 Instructions
1. Initialize a Flights structure with a dynamic array (use malloc).
2. Implement createFlight() to input flight details from the user.
3. Implement addFlight() to append a flight, resizing the array if count == max.
4. Implement removeFlight() to delete a flight by ID and shift remaining elements.
5. Implement showFlights() to display all flights.
6. Implement displayFlightInfo() to show details of a single flight.
