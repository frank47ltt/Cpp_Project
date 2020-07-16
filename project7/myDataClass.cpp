/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 16
 * project: project 7
 *************************************************************/

#include "myDataClass.h"
#include <string>
#include <iostream>

using namespace std;


// default constructor
myDataClass::myDataClass() {
    name = "unknown";
    position = "unknown";
    weight = "unknown";
    college = "unknown";
}

// constructor
myDataClass::myDataClass(string name, string position, string weight, string college) {
    this->name = name;
    this->position = position;
    this->weight = weight;
    this->college = college;
}

// overloaded comparison operator
bool myDataClass::operator<(const myDataClass &rhs) {
    if (name < rhs.name) {
        return true;
    } else {
        return false;
    }
}

bool myDataClass::operator>(const myDataClass &rhs) {
    if (name > rhs.name) {
        return true;
    } else {
        return false;
    }
}

// overloaded equality operator
bool myDataClass::operator==(const myDataClass &rhs) {
    if (name == rhs.name) {
        return true;
    } else {
        return false;
    }
}


// overloaded insertion operator
ostream &operator<<(ostream &out, const myDataClass &obj) {
    out << "Player " << obj.name << " has weigh " << obj.weight << " is a " << obj.position << " from " << obj.college
        << endl;
    return out;
}