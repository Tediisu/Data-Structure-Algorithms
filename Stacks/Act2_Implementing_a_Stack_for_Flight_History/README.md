🧱 Activity 2: Implementing a Stack for Flight History

🧠 Learning Objectives
- Apply LIFO (Last-In-First-Out) principles using arrays.
- Understand stack operations: push, pop, peek.
- Use flight data to simulate undo/history behavior.

🗂️ Structure to Define
`c

define STACK_SIZE 100

typedef struct {
    Flight stack[STACK_SIZE];
    int top;
} FlightStack;
`

🛠️ Functions to Implement
`c
void initStack(FlightStack *s);
int isStackEmpty(FlightStack s);
int isStackFull(FlightStack s);
void pushFlight(FlightStack *s, Flight f);
Flight popFlight(FlightStack *s);
Flight peekFlight(FlightStack s);
// Add the other auxiliary functions like isEmpty, isFull, makeNull/makeEmpty
`

📋 Instructions
1. Initialize the stack with top = -1.
2. Implement pushFlight() to add a flight to the stack.
3. Implement popFlight() to remove the most recent flight.
4. Implement peekFlight() to view the top flight without removing it.
5. Simulate a flight history tracker: every time a flight is added or removed, push it to the stack.
