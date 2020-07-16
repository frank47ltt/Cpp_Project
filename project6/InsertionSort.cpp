#include <iostream>
#include <vector>
#include <cassert>
#include "BinaryInsertionSort.h"
#include "Node.h"
#include "fstream"
#include "LinkedList.h"
#include "myDataClass.h"
#include <ctime>

using namespace std;

int main() {

    // define necessary variables
    ifstream inFile;
    string filename;
    int numOfEntries;

    //read the file name of your dataset
    cout << "What is the name of your data file? " << endl;
    cin >> filename;
    cout << "What is the length of your data file? " << endl;
    cin >> numOfEntries;
    cout << "You probably gonna need to wait about 50 seconds until the program finished since sorting a vector using "
         << endl;
    cout << "insertionSort is extremely slow" << endl;

    // to make it convenient, I will assign the variable correct name and length
    filename = "CSC112_Project_6_NBA_Dataset_Frank_Jingwen.csv";
    numOfEntries = 4550;
    inFile.open(filename);
    if (!inFile.is_open()) {
        cout << " Could not open NBA dataset" << endl;
        return 1; // something bad happened , return non‐zero
    }

    // define vector and linkedlist
    vector<myDataClass> v;
    LinkedList l;

    // populate the vector with the data from your data set
    string tmp;
    string name;
    string position;
    string weight;
    string college;
    // get the first line of the data first since it is the title and we really don want it
    getline(inFile, tmp);
    // use .eof to iterate until the end of the dataset
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
            l.append(a);
            v.push_back(a);
        }
    }

    // the above code iterate through the end of the dataset
    // but for purpose of making graph, I will use a for loop so I can change the input size
    /*
    for (int i = 0; i < 1000; i++){
        // use getline to get my string until the ',', which is the first column of my dataset
        getline(inFile, name, ',');  // store the first column as name
        getline(inFile, tmp, ',');   // 2nd column is useless
        getline(inFile, tmp, ',');   // 3rd column is useless
        getline(inFile, position, ',');   // store the forth column as position
        getline(inFile, weight, ',');   //  store the fifth column as weight
        getline(inFile, tmp, ',');   // 6th column is useless
        getline(inFile, college);   // store the 7th column as college
        myDataClass a(name, position, weight, college);
        l.append(a);
        v.push_back(a);
    }
    */

    // record the time
    clock_t start_LinkedList_InsertionSort = clock();
    // sort LinkedList using InsertionSort;
    l.InsertionSort();
    clock_t end_LinkedList_InsertionSort = clock();


    clock_t start_Vector_InsertionSort = clock();
    // sort Vector using InsertionSort;
    // binary insertion sort
    insertionSort(v, v.size());
    clock_t end_Vector_InsertionSort = clock();

    // print elapsed time for InsertionSort for LinkedList and Vector
    cout << "Printing out the elapsed time for InsertionSort for LinkedList and Vector" << endl;
    double elapsed_LinkedList = double(end_LinkedList_InsertionSort - start_LinkedList_InsertionSort) / CLOCKS_PER_SEC;
    double elapsed_Vector = double(end_Vector_InsertionSort - start_Vector_InsertionSort) / CLOCKS_PER_SEC;

    cout << "Time for sorting LinkedList is " << elapsed_LinkedList << endl;
    cout << "Time for sorting Vector is " << elapsed_Vector << endl;



    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i - 1] <= v[i]);
    }

    // print out sorted list
    for (int i = 0; i < v.size(); i++) {
        //you should ovrride << to YourClass
        cout << v[i] << endl;
    }


    // big three and printList debugging
    /*
    LinkedList l;
    myDataClass a("Frank","a","b","c");
    myDataClass b("Blue","a","b","c");
    myDataClass c("Jack","a","b","c");
    myDataClass e("Zoe","A","b","c");
    l.append(a);
    l.append(b);
    l.append(c);
    l.append(e);
    LinkedList d;
    d = l;
    l.InsertionSort();
    d.printList();
     */

    // FINISH ME
    // close the file
    inFile.close();
    return 0;
}