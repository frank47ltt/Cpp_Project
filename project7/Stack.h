/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 16
 * project: project 7
 *************************************************************/

#ifndef PROJECT7_STACK_H
#define PROJECT7_STACK_H

#include "LinkedList.h"
#include <iostream>

class Stack : public LinkedList {
public:
    // default constructor
    Stack();

    // add from head
    void push_head(myDataClass obj);

    // remove from head
    bool pop_head();


};


#endif //PROJECT7_STACK_H
