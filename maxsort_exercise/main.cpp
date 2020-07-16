#include <iostream>
#include <vector>
using namespace std;

// function declarations
void maxSort(vector<int>& list);
void swap(int& a, int& b);
void print(const vector<int>& list);

int main() {
    int i;
    int j;
    vector<int> v(5);  // vector to be sorted
    // initialize v
    /* your code here */
    for (i = 0; i < v.size(); i++) {
        cin >> v.at(i);
    }


    // print the unsorted v
    for (i = 0; i < v.size(); i++) {
        cout << v.at(i) << " " << endl;
    }


    // sort v
    /* your code here */
    maxSort(v);

    // print the sorted v
    /* your code here */
    for (i = 0; i < v.size(); i++) {
        cout << v.at(i) << " " << endl;
    }

    return 0;
}

/* the function definitions */

//Max sort function
void maxSort(vector<int>& list) {
    int currMax;
    int k;
    for (int i = list.size() - 1; i >= 0; i--) {
        /*complete the code*/
        currMax = list.at(0);
        for (int j = 0; j <= i; j++) {
            if (list.at(j) > currMax) {
                currMax = list.at(j);
            }

        }
        for (k = 0; k < list.size(); k++) {
            if (list.at(k) == currMax) {
                break;
            }
        }
        swap(list.at(i), list.at(k));
    }
}

// swap function
void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// print function
void print(const vector<int>& list) {
    cout << "Printing Sorted Vectors";
    for (int i = 0; i < list.size(); i++) {
        cout << list.at(i) << " ";
    }
}

