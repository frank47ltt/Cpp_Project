/************************************************************************************************************
 * Author: Frank (Tongtong) Liu
 * Date: Feb 19, 2020
 * Class: CSC112 Project 3
 * Command Line Argument (if needed): BubbleSort.exe CSC112_Project_3_NBA_Dataset_Frank.csv bubble.txt merge.txt
**************************************************************************************************************/

#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
#include <fstream>
#include <string>

using namespace std;

// MergeSort function declarations
void mergeSort(vector<string> &a, vector<string> &tmp, int left, int right);
void mergeSortedLists(vector<string> &a, vector<string> &tmp, int leftPos, int rightPos, int rightEnd);

// BubbleSort function declaration
void swap(string *a, string *b);
void bubbleSort(string *a, int n);

int main(int argc, char *argv[]) {
// the command line argument should be the follow
// BubbleSort.exe CSC112_Project_3_NBA_Dataset_Frank.csv bubble.txt merge.txt

    // declare the input file stream and output file stream
    ifstream inFile;
    ofstream outFileMerge;
    ofstream outFileBubble;
    // string that will store unused information
    string tmp;
    int counter = 0;    // being used to store the string I want into vector

    // check number of arguments, should be four
    if (argc != 4) {
        cout << "There should be four command line argument" << endl;
        cout << "BubbleSort.exe CSC112_Project_3_NBA_Dataset_Frank.csv bubble.txt merge.txt";
        return 1;
    }

    // open input and output files here with command line
    inFile.open(argv[1]);         // open the data from NBA dataset
    outFileBubble.open(argv[2]);  // create a new file that stores the sorted list using BubbleSort
    outFileMerge.open(argv[3]);   // create a new file that stores the sorted list using mergeSort

    // check if these input file and output file opened successfully
    if (!inFile.is_open()) {
        cout << " Could not open NBA dataset" << endl;
        return 1; // something bad happened , return non‐zero
    }
    if (!outFileMerge.is_open()) {
        cout << "Could not open file merge.txt." << endl;
        return 1;
    }
    if (!outFileBubble.is_open()) {
        cout << "Could not open file bubble.txt." << endl;
        return 1;
    }

    // get input: vector length which is the total number of entries in your data set
    // Dr. Alqahtani said in office hour that to ignore the instruction and hard code the length of your dataset

    vector<string> v(4551); // vector to be sorted
    vector<string> t(4551); // temporary workspace

    // define a string pointer dynamically allocate an array of strings
    string *stringPtr = new string[4551];

    // populate and print input
    cout << "Now we are printing the unsorted list" << endl;
    cout << "Unsorted:" << endl;

    // get the first line of the data first since it is the title and we really don want it
    getline(inFile, tmp);

    // use .eof to iterate until the end of the dataset
    while (!inFile.eof()) {
        if (!inFile.fail()) { // check to make sure all data is read in successfully
            // use getline to get my string until the ',', which is the first column of my dataset
            getline(inFile, tmp, ',');
            v.at(counter) = tmp;   // store the string into the vector
            getline(inFile, tmp);   // read the rest of the data in
            counter++;     // increasing the counter
        }
    }
    // print out the unsorted list that I put in the vector
    for (int j = 0; j < 4551; j++) {
        cout << v.at(j) << endl;
    }
    cout << endl;

    // copy the list of strings from vector to array
    for (int k = 0; k < 4551; k++) {
        stringPtr[k] = v.at(k);
    }

    clock_t start_mergeSort = clock();
    // sort vector using mergeSort
    // the right index is actually length - 1, so is 4550
    mergeSort(v, t, 0, 4550);
    clock_t end_mergeSort = clock();

    // check output, make sure vector is sorted after mergeSort
    for (int i = 1; i < v.size(); i++) {
        assert(v.at(i - 1) <= v.at(i));
    }

    clock_t start_bubbleSort = clock();
    // sort array using bubbleSort
    bubbleSort(stringPtr, 4551);
    clock_t end_bubbleSort = clock();

    // check output, make sure array is sorted after bubbleSort
    for (int i = 1; i < v.size(); i++) {
        assert(stringPtr[i - 1] <= stringPtr[i]);
    }

    // print sorted vector after mergeSort into "merge.txt"
    cout << "Sorted:" << endl;
    cout << "Printing sorted list to bubble.txt and merge.txt" << endl;
    for (int i = 0; i < 4551; i++) {
        outFileMerge << v.at(i) << endl;
    }
    cout << endl;

    // print sorted array after bubbleSort into file "bubble.txt"
    for (int i = 0; i < 4551; i++) {
        outFileBubble << stringPtr[i] << endl;
    }
    cout << endl;

    // unit test for swap function
    cout << "Unit test for swap function" << endl;
    cout << "Test started!" << endl;
    string a = "first one";
    string *aPtr = &a;
    string b = "second one";
    string *bPtr = &b;
    swap(aPtr, bPtr);
    cout << "swap(\"first one\" and \"second one\"), expecting \"second one\" \"first one\", got :" << a << " " << b
         << endl;
    cout << "Test end!" << endl;
    cout << endl;

    // print elapsed time for mergeSort and bubbleSort
    cout << "Printing out the elapsed time for mergeSort and bubbleSort" << endl;
    double elapsed_mergeSort = double(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;

    cout << elapsed_mergeSort << " " << elapsed_bubbleSort << endl;

    // close all related input and output file stream
    inFile.close();
    outFileMerge.close();
    outFileBubble.close();

    // delete the dynamically allocated string pointer array
    delete[] stringPtr; // free the memory of the array
    stringPtr = NULL;

    return 0;
}

void mergeSortedLists(vector<string>& a, vector<string>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }

    }

    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(vector<string>& a, vector<string>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

// Swap function
void swap(string *a, string *b) {
    // declaring tmp variable
    string tmp;
    tmp = *a;   // using * and pointer to access the content and swap
    *a = *b;
    *b = tmp;
}

// BubbleSort function
void bubbleSort(string *a, int n) {
    int i;
    int j;
    // using a nested for loop to swap adjacent two string if they are not sorted
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(a + j) > *(a + j + 1)) {
                swap(*(a + j), *(a + j + 1));    // call the swap to sort
            }
        }
    }
}
