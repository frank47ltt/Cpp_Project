#include<iostream>
#include "Node.h"
using namespace std;


Node::Node (int v ){
    value=v;
    next= nullptr;
}

int Node::getValue () const{
    return value;
}

Node* Node:: getNext () const{
    return next;
}

void Node:: setValue(int v){
    value=v;
}

void Node:: setNext(Node* n){
    next=n;
}

void Node::InsertAfter(Node* nextNode) {
    Node* tmp = this->next;
    this->next = nextNode;
    nextNode->next = tmp;
}

void Node:: printNode() const{
    cout<<this->value<<endl;
}