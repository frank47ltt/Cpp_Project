/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 8
 * project: project 6
 *************************************************************/

#ifndef BINARYINSERTIONSORT_MYDATACLASS_H
#define BINARYINSERTIONSORT_MYDATACLASS_H

#include <iostream>
#include <string>

using namespace std;


class myDataClass {
public:
    // default constructor
    myDataClass();

    // constructor
    myDataClass(string name, string position, string weight, string college);

    // overloaded operators

    bool operator<(const myDataClass &rhs);

    bool operator>(const myDataClass &rhs);

    bool operator==(const myDataClass &rhs);

    // this is defined for the assert test on InsertionSort.cpp
    bool operator<=(const myDataClass &rhs);

    // overload the insertion operator
    friend ostream &operator<<(ostream &out, const myDataClass &obj);

private:
    // four variables
    // I will use name to compare
    string name;
    string position;
    string weight;
    string college;
};


#endif //BINARYINSERTIONSORT_MYDATACLASS_H
