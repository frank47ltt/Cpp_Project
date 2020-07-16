#ifndef BINARYINSERTIONSORT_H
#define BINARYINSERTIONSORT_H

#include <vector>
#include "myDataClass.h"

using namespace std;

int binarySearch(vector<myDataClass> a, int item, int low, int high);

void insertionSort(vector<myDataClass> &a, int n);

#endif //BINARYINSERTIONSORT_H
