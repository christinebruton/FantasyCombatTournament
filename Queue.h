/*********************************************************************
 * Class: Queue
 * Abstraction the class represents: Queue-like abstract data type of doubly
 * linked circular list
 * Purpose: Store data dynamically in individual nodes. Add characters
 * to the back and remove them from the front
 * How to use: Create Queue instance and access methods
 * Summary of functionality: Access methods to add, delete
 * and print objects from the queue
 *********************************************************************/

#ifndef TOURNAMENT_QUEUE_H
#define TOURNAMENT_QUEUE_H
#include "Character.h"

#include <iostream>
using std::cout; using std::cin; using std::endl;

//struct for node object to be used in Queue class
struct QueueNode{
    //a pointer to the next Node object
    QueueNode *next= nullptr;
    //a pointer to the previous Node object
    QueueNode *prev= nullptr;

    Character *cInNode;
    //destructor for node object
    ~QueueNode();
};


class Queue {

private:

    //pointer to head of linked list
    QueueNode *head= nullptr;

public:
    //checks if the queue is empty. If so, returns true; otherwise, return false.
    bool isEmpty();
    // takes a user-inputted integer, creates a QueueNode with user-inputted integer, and appends it to the back of the list.
    void enqueue(Character *c);
    //returns the value of the node at the front of the queue.
    Character * getFront();
    //removes the front QueueNode of the queue and free the memory.
    void dequeue();
    //traverses through the queue from head using next pointers, and prints the values of each QueueNode in the queue.
    void printQueue();

    //void push(Character *c);
    //constructor
    Queue();
    //destructor
    ~Queue();

    void removeNodes();
};



#endif //TOURNAMENT_QUEUE_H
