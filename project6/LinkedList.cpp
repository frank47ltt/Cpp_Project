/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 8
 * project: project 6
 *************************************************************/

#include "LinkedList.h"
#include <iostream>
#include "myDataClass.h"

// define the default constructor
LinkedList::LinkedList() {
    head = nullptr;
}

// define the copy constructor
LinkedList::LinkedList(const LinkedList &list) {
    cout << "copy constructor called" << endl;
    // creating head for the copied node
    Node *listCursor = list.head;
    if (listCursor != nullptr) {
        head = new Node(listCursor->value, nullptr);
    }
    // iterate through the original list and copy Node
    Node *cursor = head;
    while (listCursor->next != nullptr) {
        listCursor = listCursor->next;
        cursor->next = new Node(listCursor->value, nullptr);
        cursor = cursor->next;
    }
}

//Assignment Operator
LinkedList &LinkedList::operator=(const LinkedList &rhs) {
    cout << "assignment operator called" << endl;
    LinkedList tmp(rhs);
    // use copy constructor to create a local copy and swap the head
    swap(head, tmp.head);
    return *this;
}

//Destructor
LinkedList::~LinkedList() {
    Node *tmp;
    Node *current = head;
    while (current != nullptr) {
        tmp = current->next;
        current->next = nullptr;
        delete current;
        current = tmp;
    }
}

//Functions. You may not need to use them all
// appending function
void LinkedList::append(myDataClass obj) {
    //situations when there's empty list
    if (head == nullptr) {
        head = new Node(obj, nullptr);
    }
        // list is not empty
    else {
        Node *cursor = head;
        while (cursor->next != nullptr) {
            cursor = cursor->next;
        }
        cursor->next = new Node(obj, nullptr);
    }
}

bool LinkedList::Delete(myDataClass obj) {
    //empty list
    if (head = nullptr) {
        return false;
    }
    //item is the first node
    Node *current = head;
    Node *previous;
    myDataClass a = current->value;
    if (a == obj) {
        head = head->next;
        current->next = nullptr;
        delete current;
        return true;
    } else {
        //item is in the list
        while (current != nullptr) {
            if (current->value == obj) {
                previous->next = current->next;
                current->next = nullptr;
                delete current;
                return true;
            }
            previous = current;
            current = current->next;
        }
    }

    //item not find
    return false;
}

myDataClass LinkedList::find(myDataClass obj) {
    Node *cursor = head;
    while (cursor != nullptr) {
        if (cursor->value == obj) {
            return obj;
        }
        cursor = cursor->next;
    }
    // we cannot return anything if object is not find so I print out a statement
    cout << "Object no found" << endl;
}

void LinkedList::printList() {
    Node *cursor = head;
    if (cursor == nullptr) {
        cout << "empty list" << endl;
    }
        // iterate through the list and print each node
    else {
        while (cursor != nullptr) {
            cout << cursor->value << endl;
            cursor = cursor->next;
        }
    }
}

// sort the already existed list
void LinkedList::InsertionSort() {
    Node *cursor = head;
    Node *previous;
    cursor = cursor->next;
    while (cursor != nullptr) {
        previous = head;
        // sort from the beginning of the node
        while (previous != cursor) {
            if (previous->value > cursor->value) {
                swap(previous->value, cursor->value);
            } else {
                previous = previous->next;
            }
        }
        cursor = cursor->next;
    }
}

// sort while inserting
void LinkedList::sortThenInsert(myDataClass obj) {
    Node *cursor = head;
    // simply append if it is an empty list
    if (head == nullptr) {
        this->append(obj);
    } else {
        while (cursor->next != nullptr) {
            if (obj < cursor->value) {
                head = new Node(obj, cursor);
                // break out if it is the smallest (smaller than the head)
                break;
            } else if (obj > cursor->value && obj < cursor->next->value) {
                Node *tmp = cursor->next;
                cursor->next = new Node(obj, tmp);
                // break out in the middle if in the right position
                break;
            }
                // keep searching
            else {
                cursor = cursor->next;
            }
        }
        // situations when the node is the largest
        if (cursor->next == nullptr) {
            cursor->next = new Node(obj, nullptr);
        }
    }
}



