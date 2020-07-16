
/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 16
 * project: project 7
 *************************************************************/

#ifndef PROJECT7_QUEUE_H
#define PROJECT7_QUEUE_H


#include "LinkedList.h"
#include <iostream>

class Queue : public LinkedList {
public:
    // default constructor
    Queue();

    // big three
    ~Queue();

    Queue(const Queue &obj);

    const Queue &operator=(Queue rhs);

    // add at tail
    void enqueue_tail(myDataClass obj);

    // remove at head
    bool dequeue_head();


private:
    // keep track of tail using a tail pointer
    Node *tail;
};


#endif //PROJECT7_QUEUE_H
