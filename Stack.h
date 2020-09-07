/*********************************************************************
 * Class: Stack
 * Abstraction the class represents: Stack-like abstract data type of doubly
 * linked circular list
 * Purpose: Store data dynamically in individual nodes. Add characters
 * to the front and display them in reverse order
 * How to use: Create Stack instance and access methods
 * Summary of functionality: Access methods to add, delete
 * and print objects from the stack
 *********************************************************************/

#ifndef TOURNAMENT_STACK_H
#define TOURNAMENT_STACK_H
#include "Character.h"
#include <iostream>
using std::cout; using std::cin; using std::endl;

//struct for node object to be used in Queue class
struct StackNode{
    //a pointer to the next Node object
    StackNode *next= nullptr;
    //a pointer to the previous Node object
    StackNode *prev= nullptr;
    Character *cInNode;
    //destructor for node object
    ~StackNode();
};


class Stack {

private:
    StackNode *head= nullptr;

public:

    //adds object to the front of the list
    void push(Character *c);
    //determines if stack is empyt
    bool isEmpty();
    //removes object from front of list
    void pop();
    //Print all values in the stack in reverse order
    void revPrintStack();
    //destructor
    ~Stack();
    //frees memory in each node
    void removeSNodes();
};


#endif //TOURNAMENT_STACK_H
