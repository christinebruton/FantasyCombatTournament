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

#include "Queue.h"

/*********************************************************************
 * Function: isEmpty
 * Purpose: Determines if the list is empty, used in other functions
 * Arguments|Preconditions: none
 * Return Type: bool
 *********************************************************************/

bool Queue::isEmpty() {

    if (head== nullptr){

        return true;
    } else {
        return false;
    }
}

/*********************************************************************
 * Function: addBack
 * Purpose: Add a new node to the end of the queue and put user-entered
 * value int it.
 * Arguments|Preconditions: int value from user
 * Return Type: void
 *********************************************************************/

void Queue::enqueue(Character *c) {
    QueueNode *n = new QueueNode();
    //if no node, create one
    if (isEmpty()) {
        //put character in the node
        n->cInNode=c;
        n->next = n->prev = n;
        head = n;
    } else {

        //locate back of the queue, create a temp pointer for that
        QueueNode *back=(head->prev);
        n->cInNode=c;
        //move the head to next slot of the new pointer
        n->next = head;
        //move new node to the prev position of the head
        head->prev = n;
        //set the back to the prev position of the new node
        n->prev = back;
        //set the back next pointer
        back->next = n;
    }
}

/*********************************************************************
 * Function: getFront
 * Purpose: return the
 * Arguments|Preconditions: none
 * Return Type: int
 *********************************************************************/

Character * Queue::getFront() {
    while (!isEmpty()) {
        QueueNode *temp=head;
        if (temp==head){
           // cout<<"Name at the front of queue: "<<temp->cInNode->getName()<<endl;
        }
        return temp->cInNode;
    }
    return head->cInNode;
}

/*********************************************************************
 * Function: removeFront
 * Purpose: Remove the first node in the list. Rearrange pointers to retain
 * list structure
 * Arguments|Preconditions: none
 * Return Type: void
 *********************************************************************/

void Queue::dequeue() {
    QueueNode *temp=head, *previous= nullptr;

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
 * Function: printQueue
 * Purpose: Print all values in the queue or indicate if list is empty
 * Arguments|Preconditions: none
 * Return Type: void
 *********************************************************************/

void Queue::printQueue() {
    QueueNode *temp=head;
    if (isEmpty()){
        cout<<"*** Empty List! *** "<<endl;
        return;
    }
    else{
        cout<<"Characters in queue: ";
        while (temp->next != head){
            //access and print the character from the list
            cout<<temp->cInNode->getName()<<", ";
            temp=temp->next;
        }
        cout<<temp->cInNode->getName()<<endl;
    }
}


/*********************************************************************
 * Function: emptyQueue
 * Purpose: Print all values in the queue or indicate if list is empty
 * Arguments|Preconditions: none
 * Return Type: void
 *********************************************************************/


//constructor
Queue::Queue() {

}

//destructor taken from textbook example in linked list chapter
Queue::~Queue() {

    QueueNode *temp = head;
    {
        // garbage keeps track of node to be deleted
        QueueNode *garbage = temp;
        //Move on to the next node, if any

        if (!isEmpty()){

            temp = temp->next;
        }
        // Delete the '' garbage'' node
        delete garbage;
    }
}
//node destructor
QueueNode::~QueueNode() = default;

//function to remove nodes based on this thread
//https://stackoverflow.com/questions/43149249/c-circular-link-list-remove-all-nodes
void Queue::removeNodes() {
    if(this->head == nullptr)
        return;
    QueueNode *traversePointer = this->head;
    QueueNode *deletePointer;
    do{
        deletePointer = traversePointer;
        traversePointer = traversePointer->next;
        delete deletePointer;
    }while(traversePointer != this->head);
    this->head = nullptr;

}

