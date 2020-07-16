//
// Created by Frankky Boy on 2/18/2020.
//
#include <string>
#include "Faculty.h"

using namespace std;

Faculty::Faculty() {
    name = "unknown";
    id = "unknown";
    department = "unknown";
    degree = "unknown";
}

Faculty::Faculty(string a, string b, string c, string d) {
    name = a;
    id = b;
    department = c;
    degree = d;
}

void Faculty::setName(string userName) {
    name = userName;
}

void Faculty::setID(string userID) {
    id = userID;
}

void Faculty::setDepartment(string userDepartment) {
    department = userDepartment;
}

void Faculty::setDegree(string userDegree) {
    degree = userDegree;
}

string Faculty::getName() const {
    return name;
}

string Faculty::getID() const {
    return id;
}

string Faculty::getDepartment() const {
    return department;
}

string Faculty::getDegree() const {
    return degree;
}

