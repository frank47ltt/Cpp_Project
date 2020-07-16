/**************************
 * Name: Frank Liu(Tongtong)
 * Project: CSC112 Lab 2
 * Date: Feb 2, 2020
 *************************/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// function declarations
void mergeSort(vector<int> &a, vector<int> &tmp, int left, int right);

void mergeSortedLists(vector<int> &a, vector<int> &tmp, int left, int middle, int right);

int main() {
    cout << "Please enter the random seed and the vector length" << endl;
    // get input: first is random seed, second is vector length
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace

    // unit test for merge
    cout << "Unit Testing started!" << endl;
    vector<int> testVector{1, 3, 2};
    cout << "expecting: 1\t2\t3\t" << endl;    // using pre calculated result to compare
    cout << "got:       ";
    mergeSort(testVector, t, 0, testVector.size() - 1);
    for (int i = 0; i < testVector.size(); i++) {
        cout << testVector.at(i) << '\t';
    }
    cout << endl;
    cout << "Testing completed!" << endl;
    cout << endl;

    // initialize and print input
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v, t, 0, v.size() - 1);

    // print output
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v.at(i - 1) <= v.at(i));
    }

    return 0;
}

// functions declaration
void mergeSort(vector<int> &a, vector<int> &tmp, int left, int right) {
    // create middle index to split the vector into half
    int middle;
    // recursive statement break out (not calling itself anymore) when the left index is not smaller then right anymore
    if (right - left == 0) {
        return;      // return when the length of the vector equals 1 (left index equals right index)
    }
    if (left < right) {
        middle = (left + right) / 2;
        // recursive statement to call mergeSort again to split it half
        mergeSort(a, tmp, left, middle);
        mergeSort(a, tmp, middle + 1, right);
        // call the function that merge the vectors back
        mergeSortedLists(a, tmp, left, middle, right);
    }
}

void mergeSortedLists(vector<int> &a, vector<int> &tmp, int left, int middle, int right) {
    // three int variables that keep track of the index when doing comparison
    int vectorLeftIndex = left;
    int vectorRightIndex = middle + 1;
    int tmpVectorIndex = 0;
    // enter while loop while both vector is not empty
    while ((vectorLeftIndex <= middle) && (vectorRightIndex <= right)) {
        // put the smaller element of both vector into the tmp vector after comparison
        if (a.at(vectorLeftIndex) < a.at(vectorRightIndex)) {
            tmp.at(tmpVectorIndex) = a.at(vectorLeftIndex);
            vectorLeftIndex++;
        } else {
            tmp.at(tmpVectorIndex) = a.at(vectorRightIndex);
            vectorRightIndex++;
        }
        tmpVectorIndex++;
    }
    // enter the following while loop when one of the two vectors is empty
    // simply put the rest of the element in tmp vector in order
    while (vectorLeftIndex <= middle) {
        tmp.at(tmpVectorIndex) = a.at(vectorLeftIndex);
        vectorLeftIndex++;
        tmpVectorIndex++;
    }
    while (vectorRightIndex <= right) {
        tmp.at(tmpVectorIndex) = a.at(vectorRightIndex);
        vectorRightIndex++;
        tmpVectorIndex++;
    }
    // copy the sorted element from tmp to vector a
    for (int i = left; i <= right; i++) {
        a.at(i) = tmp.at(i - left);
    }
}