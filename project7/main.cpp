/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 16
 * project: project 7
 *************************************************************/
#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <fstream>

int main() {

    // define necessary variables
    ifstream inFile;
    ofstream outFileStack;
    ofstream outFileQueue;

    //read the file name of your dataset
    inFile.open("CSC112_Project_7_NBA_Dataset_Frank_Jingwen.csv");
    outFileStack.open("stacked.txt");
    outFileQueue.open("queued.txt");

    // check if file can be opened
    if (!inFile.is_open()) {
        cout << " Could not open NBA dataset" << endl;
        return 1; // something bad happened , return non‐zero
    }
    if (!outFileStack.is_open()) {
        cout << "Could not open file stacked.txt" << endl;
        return 1;
    }
    if (!outFileQueue.is_open()) {
        cout << "Could not open file queued.txt" << endl;
        return 1;
    }


    // declare stack and queue
    Stack s;
    Queue q;

    // populate the Stack with the data from your data set
    string tmp;
    string name;
    string position;
    string weight;
    string college;
    // get the first line of the data first since it is the title and we really don want it
    getline(inFile, tmp);
    // use .eof to iterate until the end of the dataset
    cout << "Reading ... CSC112_Project_7_NBA_Dataset_Frank_Jingwen.csv..." << endl;
    while (!inFile.eof()) {
        if (!inFile.fail()) { // check to make sure all data is read in successfully
            // use getline to get my string until the ',', which is the first column of my dataset
            getline(inFile, name, ',');  // store the first column as name
            getline(inFile, tmp, ',');   // 2nd column is useless
            getline(inFile, tmp, ',');   // 3rd column is useless
            getline(inFile, position, ',');   // store the forth column as position
            getline(inFile, weight, ',');   //  store the fifth column as weight
            getline(inFile, tmp, ',');   // 6th column is useless
            getline(inFile, college);   // store the 7th column as college
            myDataClass a(name, position, weight, college);
            s.push_head(a);
            q.enqueue_tail(a);
        }
    }

    /*
    //Write out stack
    cout << "Start to print stack" << endl;
    s.print(cout);
    cout << "Start to print queue" << endl;
    q.print(cout);
     */

    // write data into output file stream
    cout << "Writing data in stack inserted at head into stacked.txt" << endl;
    s.print(outFileStack);
    cout << "Writing data in queue inserted at tail into queued.txt" << endl;
    q.print(outFileQueue);


    //empty the stack
    bool isEmpty = false;
    while (!isEmpty) {
        if (s.pop_head()) {
            s.pop_head();
            isEmpty = false;
        } else {
            isEmpty = true;
        }
    }

    // empty the queue
    isEmpty = false;
    while (!isEmpty) {
        if (q.dequeue_head()) {
            q.dequeue_head();
            isEmpty = false;
        } else {
            isEmpty = true;
        }
    }

    // nothing will be printing out since both lists are empty
    s.print(cout);
    q.print(cout);
    cout << "End" << endl;


    // close necessary file
    inFile.close();
    outFileQueue.close();
    outFileStack.close();



    /*
     // debug for Queue class
    Queue q;
    myDataClass a("A", "a", "b", "c");
    myDataClass b("B", "a", "b", "c");
    myDataClass c("C", "a", "b", "c");
    myDataClass d("D", "A", "b", "c");
    q.enqueue_tail(a);
    q.enqueue_tail(b);
    q.enqueue_tail(c);
    q.enqueue_tail(d);
    q.dequeue_head();
    q.print(cout);
    q.dequeue_head();
    q.print(cout);
     */

    /*
    // debugginig for Stack class
    Stack s;
    myDataClass a("A", "a", "b", "c");
    myDataClass b("B", "a", "b", "c");
    myDataClass c("C", "a", "b", "c");
    myDataClass d("D", "A", "b", "c");
    s.push_head(a);
    s.push_head(b);
    s.push_head(c);
    s.push_head(d);
    s.print(cout);
    s.pop_head();
    s.print(cout);
     */



    return 0;
}