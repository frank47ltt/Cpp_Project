//
// Created by Frankky Boy on 2/18/2020.
//
#include <string>

#ifndef CLASS11_FACULTY_H
#define CLASS11_FACULTY_H
using namespace std;

class Faculty {
public:
    Faculty();  // default
    Faculty(string a, string b, string c, string d);   // general Constructor
    void setName(string userName);

    void setID(string userID);

    void setDepartment(string userDepartment);

    void setDegree(string userDegree);

    string getName() const;

    string getID() const;

    string getDepartment() const;

    string getDegree() const;

private:
    string name;
    string id;
    string department;
    string degree;

};

#endif //CLASS11_FACULTY_H
