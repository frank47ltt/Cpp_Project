/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 8
 * project: project 6
 *************************************************************/

#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include "myDataClass.h"
using namespace std;

class LinkedList{

public:
    //Constructors
    LinkedList();

    // copy constructor
    LinkedList(const LinkedList &list);

    //Assignment Operator
    LinkedList &operator=(const LinkedList &rhs);

    //Destructor
    ~LinkedList();

    //Functions. You may not need to use them all
    void append(myDataClass obj);

    bool Delete(myDataClass obj);

    myDataClass find(myDataClass obj);

    void printList();

    void InsertionSort();

    void sortThenInsert(myDataClass obj);

private:
    Node *head;

};

#endif //BINARYINSERTIONSORT_LINKEDLIST_H