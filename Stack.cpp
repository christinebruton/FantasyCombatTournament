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

#include "Stack.h"
/*********************************************************************
 * Function: isEmpty
 * Purpose: Determines if the list is empty, used in other functions
 * Arguments|Preconditions: none
 * Return Type: bool
 *********************************************************************/

bool Stack::isEmpty() {

    if (head== nullptr){

        return true;
    } else {
        return false;
    }
}

/*********************************************************************
 * Function: push
 * Purpose: add character to first node in the stack
 * Arguments|Preconditions: none
 * Return Type: void
 *********************************************************************/

void Stack::push(Character *c)
{
    StackNode *n = new StackNode;

    if (isEmpty()) {
        n->cInNode=c;
        n->next = n->prev = n;
        head = n;

    } else {
        StackNode *final = (head->prev);

        n->cInNode= c;
        n->prev = final;
        n->next = head;

        final->next = head->prev = n;

        head = n;
    }
}

/*********************************************************************
 * Function: pop
 * Purpose: Remove the first node in the stack.
 * Arguments|Preconditions: none
 * Return Type: void
 *********************************************************************/

void Stack::pop() {
    StackNode *temp=head, *previous= nullptr;

    if(!isEmpty()) {
        //if the first node
        if (temp==head ){
            //change previous to the last node
            previous=head->prev;
            //move the head forward
            head= head->next;
            previous->next=head;
            head->prev=previous;

            //free memory
            free(temp);

        }//check if you are looking at the last node
        if(head->prev==temp) {
            head= nullptr;
        }
    }
}

/*********************************************************************
 * Function: rePrintStack
 * Purpose: Print all values in the stack in reverse order
 * or indicate if list is empty
 * Arguments|Preconditions: none
 * Return Type: void
 *********************************************************************/

void Stack::revPrintStack() {
    StackNode *temp = head;
    if (isEmpty()){
        cout<<"*** Empty List! *** "<<endl;
        return;
    }else{
        while (temp->prev != head)
        {
            cout<<temp->cInNode->getName()<<", ";;
            temp = temp->prev;
        }
        cout<<temp->cInNode->getName()<<", "<<endl;
    }
}

//function to delete all nodes taken from https://stackoverflow.com/questions/43149249/c-circular-link-list-remove-all-nodes
void Stack::removeSNodes() {
    if(this->head == nullptr)
        return;
    StackNode *traversePointer = this->head;
    StackNode *deletePointer;
    do{
        deletePointer = traversePointer;
        traversePointer = traversePointer->next;
        delete deletePointer;
    }while(traversePointer != this->head);
    this->head = nullptr;

}

//destructor taken from textbook example in linked list chapter
Stack::~Stack() {

    StackNode *temp = head;
    {
        // garbage keeps track of node to be deleted
        StackNode *garbage = temp;
        //Move on to the next node, if any

        if (!isEmpty()){
            temp = temp->prev;
        }
        // Delete the '' garbage'' node
        delete garbage;
    }
}


StackNode::~StackNode() {

}

