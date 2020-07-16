/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 16
 * project: project 7
 *************************************************************/

#include "Stack.h"
// default constructor
Stack::Stack() {
    head = nullptr;
}
// Last in first out

//add from head
void Stack::push_head(myDataClass obj) {
    // not a empty list
    if (head != nullptr) {
        Node *cursor = head;
        head = new Node(obj, cursor);
    }
        // empty list
    else {
        head = new Node(obj, nullptr);
    }

}

// remove from head
bool Stack::pop_head() {
    // not a empty list
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

