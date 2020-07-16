/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 16
 * project: project 7
 *************************************************************/
#include "Queue.h"

//default constructor
Queue::Queue() {
    head = nullptr;
    tail = nullptr;
}

//destructor
Queue::~Queue() {
    delete tail;
}

//copy constructor
Queue::Queue(const Queue &obj) {
    this->tail = new Node(obj.tail->item, obj.tail);
}

//copy assignment overloading operator
const Queue &Queue::operator=(Queue rhs) {
    swap(this->tail, rhs.tail);
    return *this;
}

//first in first out

//enqueue function, adding node at the tail of the linked list
void Queue::enqueue_tail(myDataClass obj) {
    // not empty list
    if (head != nullptr) {
        Node *cursor = head;
        // iterate to the end
        while (cursor->next != nullptr) {
            cursor = cursor->next;
        }
        // add node and move tail pointer
        cursor->next = new Node(obj, nullptr);
        tail = cursor->next;
    }
        // empty list
    else {
        head = new Node(obj, nullptr);
        tail = head;

    }
}

//dequeue function, deleting node form the head of the linked list
bool Queue::dequeue_head() {
    // not an empty list
    if (head != nullptr) {
        Node *cursor = head->next;
        // delink the node and delete
        head->next = nullptr;
        delete head;
        head = cursor;
        return true;
    }
        // empty list
    else {
        return false;
    }
}
