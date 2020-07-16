/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 16
 * project: project 7
 *************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "myDataClass.h" //You need to create this

class Node {
public:
    myDataClass item; // object at node
    Node *next; // pointer to next node

    Node(const myDataClass &d, Node *n = nullptr) {
        item = d;
        next = n;
    }
};

class LinkedList {
    // variables should be protected in order to be accessed by derived class
protected:
    Node *head;
public:
    LinkedList();
    LinkedList(const LinkedList& list);
    const LinkedList& operator=(LinkedList rhs);
    void print(ostream &os);
    void pop_head();
    ~LinkedList();
};

#endif //LINKEDLIST_H
