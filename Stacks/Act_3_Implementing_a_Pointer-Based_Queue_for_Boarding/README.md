🔄 Activity 3: Implementing a Pointer-Based Queue for Boarding

🧠 Learning Objectives
- Apply FIFO (First-In-First-Out) principles using linked lists.
- Understand dynamic memory allocation with pointers.
- Simulate real-world queuing behavior for flight boarding.

🗂️ Structures to Define
`c
typedef struct Node {
    Flight data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} FlightQueue;
`

🛠️ Functions to Implement
`c
void initQueue(FlightQueue *q);
int isQueueEmpty(FlightQueue q);
void enqueueFlight(FlightQueue *q, Flight f);
Flight dequeueFlight(FlightQueue *q);
Flight peekQueue(FlightQueue q);
`

📋 Instructions
1. Initialize the queue with front = rear = NULL.
2. Implement enqueueFlight() to add a flight to the rear.
3. Implement dequeueFlight() to remove a flight from the front.
4. Implement peekQueue() to view the next flight to board.
5. Simulate a boarding queue: enqueue flights in order and dequeue them as they board.

---

🧑‍🏫 Instructor Notes
- Encourage students to modularize their code into .h and .c files.
- Use real-world Philippine airline data or mock data for testing.
