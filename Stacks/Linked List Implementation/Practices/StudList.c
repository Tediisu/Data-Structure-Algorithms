#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

typedef char String[32];
typedef struct 
{ 
    String fName;
    char mName;
    String lName;
} Name;

typedef struct 
{
    Name name;
    int year;
    int age;
    char sex;
    String program;
} Stud;

typedef struct Node 
{
    Stud data;
    struct Node *nextStud;
} NodeType, *NodePtr, *StudList;

void init(StudList *S);
bool push(StudList *S, Stud student);
bool pop(StudList *S);
Stud peek(StudList S);
void display(StudList S);
void visualize(StudList S);

int main(void) 
{


    return 0;
}

void init(StudList *S)
{
    *S = NULL;
}

bool push(StudList *S, Stud student)
{
    
}

bool pop(StudList *S);
Stud peek(StudList S);
void display(StudList S);
void visualize(StudList S);