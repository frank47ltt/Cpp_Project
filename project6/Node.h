/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 8
 * project: project 6
 *************************************************************/
#ifndef NODE_H
#define NODE_H

#include "myDataClass.h"

class Node {
public:
    // Node constructor
    Node(myDataClass v, Node *n = nullptr) {
        value = v;
        next = n;
    }

    //Destructor
    ~Node(){
        delete next;
    }

    friend class LinkedList;
private:
    // member variables
    myDataClass value;
    Node *next;

};

#endif //NODE_H
