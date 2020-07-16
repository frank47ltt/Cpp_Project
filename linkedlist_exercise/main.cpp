#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Node.h"

using namespace std;
//Frank Liu and Zhang Jingwen
int main() {
    int x;
    Node* head= new Node();
    Node* current= head;
    cout<<"enter a list of integers and -1 to stop"<<endl;
    cin>>x;
    //populate the linked list with at least 7 nodes
    while(x!=-1){
       Node* n= new Node(x);
       current->InsertAfter(n);
       current=n; //current=current->getNext;
       cin>>x;

    }

    //print the nodes of the linked list
    current = head->getNext();
    while (current != nullptr) {
        current->printNode();
        current = current->getNext();
    }

    //1) find the node that has the minimum value
    cout << "Printing the minimum value of the list" << endl;
    current = head->getNext();
    int min = current->getValue();
    while (current != nullptr) {
        if ((current->getValue() < min)) {
            min = current->getValue();
        }
        current = current->getNext();
    }
    cout << min << endl;

    cout << "Now Removing the 4th node from the list" << endl;
    //2) remove the 4th node from the list
    current = head->getNext();
    // move the current to the third element
    for (int i = 1; i < 3; i++) {
        current = current->getNext();
    }
    // move the tmp to the fourth element so you could delete tmp and link the third and fifth element
    Node *tmp = current->getNext();
    current->setNext(tmp->getNext());
    delete tmp;

    // print out the list without fourth item
    current = head->getNext();
    while (current != nullptr) {
        current->printNode();
        current = current->getNext();
    }
    //3) remove the last node
    cout << "Remove the last item" << endl;
    current = head->getNext();
    while (current->getNext()->getNext() != nullptr) {
        current = current->getNext();
    }
    current->setNext(nullptr);
    current = current->getNext();
    delete current;

    // print out the list without last item
    current = head->getNext();
    while (current != nullptr) {
        current->printNode();
        current = current->getNext();
    }

    //4) remove the first node

    cout << "Remove the first node" << endl;
    current = head->getNext();
    head->setNext(current->getNext());
    // print out the list without first item
    current = head->getNext();
    while (current != nullptr) {
        current->printNode();
        current = current->getNext();
    }
    //6) delete all nodes
    cout << "Remove all node" << endl;
    current = head->getNext();
    while (current != nullptr) {
        current->setNext(nullptr);
        delete current;
        current = current->getNext();
    }

    return 0;
}