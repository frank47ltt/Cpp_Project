/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 8
 * project: project 6
 *************************************************************/
#include "BinaryInsertionSort.h"
using namespace std;

int binarySearch(vector<myDataClass> a, myDataClass item, int low, int high) {
    if (high <= low) {
        return (item > a[low] ? (low + 1) : low);
    }

    // middle index
    int mid = (low + high) / 2;

    // found it
    if (item == a[mid])
        return mid + 1;

    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high); // look right
    else
        return binarySearch(a, item, low, mid - 1); // look left
}

void insertionSort(vector<myDataClass> &a, int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        myDataClass selected = a[i];
        // find location where selected should be inserted
        int loc = binarySearch(a, selected, 0, j);

        // move all elements after location to create space
        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }
        a[loc] = selected;
    }
}
