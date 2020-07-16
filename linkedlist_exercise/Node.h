//
// Created by sarra on 10/21/2019.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

class Node{
public:
    Node (int v = 0);
    int getValue () const;
    Node* getNext ()const;
    void setValue(int v);
    void setNext(Node* n);
    void InsertAfter(Node* nextNode);
    void printNode() const;


private :
    int value ; // value
    Node * next ; // pointer to next node
};
#endif //LINKEDLIST_NODE_H
