
/*************************************************************
 * author: Frank Liu (Tongtong) & Selina Zhang (Jingwen)
 * class: CSC112
 * date: Apr 23
 * project: project 8
 *************************************************************/

#include "myDataClass.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


// implemented Bubble Sort from class PowerPoint
template<typename T>
void bubbleSort(vector<T> &arr, int size) {
    int i;
    int j;
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++) {
            if (arr.at(j) > arr.at(j + 1)) {
                swap(arr.at(j), arr.at(j + 1));
                swapped = true;
            }
        }
        // if swapped remain false during this time, the list will be already sorted and the it will break out the outer for loop
        if (!swapped) {
            break;
        }
    }
}

// implemented Selection Sort from class PowerPoint
template<typename T>
void minSort(vector <T>& arr, int size){
    int min;
    for(int i = 0; i < size - 1; ++i){
        //find the index of the smallest remaining element
        min = i;
        for (int j = i + 1; j < size; ++j){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

// implemented Merge Sort from Frank's previous projects
template<typename T>
void mergeSortedLists(vector<T> &a, vector<T> &tmp, int left, int middle, int right) {
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

template<typename T>
void mergeSort(vector<T> &a, vector<T> &tmp, int left, int right) {
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

// main function to test the three sorting algorithms
int main() {
    // minSort function in this project is the same thing as selection sort

    // define seed for random number generator
    srand(time(0));
    // define necessary variables
    ifstream inFile;
    //read the file name of your dataset
    inFile.open("CSC112_Project_8_NBA_Dataset_Frank_Jingwen.csv");
    // check if file can be opened
    if (!inFile.is_open()) {
        cout << " Could not open NBA dataset" << endl;
        return 1; // something bad happened , return non‐zero
    }


    // declare necessary variables and vector
    vector<myDataClass> dataV;
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
            // push the data object into a vector
            dataV.push_back(a);
        }
    }

    // the above code iterate through the end of the dataset
    // but for purpose of making graph, I will use a for loop so I can change the input size
    /*
    for (int i = 0; i < 4551; i++){
        // use getline to get my string until the ',', which is the first column of my dataset
        getline(inFile, name, ',');  // store the first column as name
        getline(inFile, tmp, ',');   // 2nd column is useless
        getline(inFile, tmp, ',');   // 3rd column is useless
        getline(inFile, position, ',');   // store the forth column as position
        getline(inFile, weight, ',');   //  store the fifth column as weight
        getline(inFile, tmp, ',');   // 6th column is useless
        getline(inFile, college);   // store the 7th column as college
        myDataClass a(name, position, weight, college);
        dataV.push_back(a);
    }
    */

    // create 4 copies of dataV into three new vector
    vector<myDataClass> dataV_B = dataV;
    vector<myDataClass> dataV_S = dataV;
    vector<myDataClass> dataV_M = dataV;
    vector<myDataClass> dataTmp(dataV.size());

    // sort the three vectors using different algorithms and count the time
    // UD stands for unsorted data
    clock_t start_bubbleSort_UD = clock();
    bubbleSort<myDataClass>(dataV_B, dataV_B.size());
    clock_t end_bubbleSort_UD = clock();

    clock_t start_minSort_UD = clock();
    minSort<myDataClass>(dataV_S, dataV_S.size());
    clock_t end_minSort_UD = clock();

    clock_t start_mergeSort_UD = clock();
    mergeSort<myDataClass>(dataV_M, dataTmp, 0, dataV_M.size() - 1);
    clock_t end_mergeSort_UD = clock();

    // print elapsed time for mergeSort and bubbleSort
    cout << "Print the time to sort UNSORTED DATA" << endl;
    double elapsed_mergeSort_UD = double(end_mergeSort_UD - start_mergeSort_UD) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort_UD = double(end_bubbleSort_UD - start_bubbleSort_UD) / CLOCKS_PER_SEC;
    double elapsed_minSort_UD = double(end_minSort_UD - start_minSort_UD) / CLOCKS_PER_SEC;
    cout << "MergeSort " << elapsed_mergeSort_UD << endl
         << "BubbleSort " << elapsed_bubbleSort_UD << endl
         << "SelectionSort " << elapsed_minSort_UD << endl << endl;

    // code for debug
    /*
    for (int i = 0; i < 4550; i++) {
        cout << dataV_B.at(i) << endl;
        cout << dataV_S.at(i) << endl;
        cout << dataV_M.at(i) << endl;

    }
     */

    // populate a vector with random integers
    vector<int> intV(4551);
    for (int i = 0; i < 4551; i++) {
        intV.at(i) = rand() % 100;
    }

    // create copies of the integer vector
    vector<int> intV_B = intV;
    vector<int> intV_S = intV;
    vector<int> intV_M = intV;
    vector<int> intTmp(intV.size());

    // sort the three vectors using different algorithms and count the time
    // UI stands for unsorted int
    clock_t start_bubbleSort_UI = clock();
    bubbleSort<int>(intV_B, intV_B.size());
    clock_t end_bubbleSort_UI = clock();

    clock_t start_minSort_UI = clock();
    minSort<int>(intV_S, intV_S.size());
    clock_t end_minSort_UI = clock();

    clock_t start_mergeSort_UI = clock();
    mergeSort<int>(intV_M, intTmp, 0, intV_M.size() - 1);
    clock_t end_mergeSort_UI = clock();

    // print elapsed time for mergeSort and bubbleSort
    cout << "Print the time to sort UNSORTED INTEGER" << endl;
    double elapsed_mergeSort_UI = double(end_mergeSort_UI - start_mergeSort_UI) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort_UI = double(end_bubbleSort_UI - start_bubbleSort_UI) / CLOCKS_PER_SEC;
    double elapsed_minSort_UI = double(end_minSort_UI - start_minSort_UI) / CLOCKS_PER_SEC;
    cout << "MergeSort " << elapsed_mergeSort_UI << endl
         << "BubbleSort " << elapsed_bubbleSort_UI << endl
         << "SelectionSort " << elapsed_minSort_UI << endl << endl;

    // the following code will resort the sorted vector to see if there's any change in time

    // sort the three vectors using different algorithms and count the time
    // SD stands for sorted data
    clock_t start_bubbleSort_SD = clock();
    bubbleSort<myDataClass>(dataV_B, dataV_B.size());
    clock_t end_bubbleSort_SD = clock();

    clock_t start_minSort_SD = clock();
    minSort<myDataClass>(dataV_S, dataV_S.size());
    clock_t end_minSort_SD = clock();

    clock_t start_mergeSort_SD = clock();
    mergeSort<myDataClass>(dataV_M, dataTmp, 0, dataV_M.size() - 1);
    clock_t end_mergeSort_SD = clock();

    // print elapsed time for mergeSort and bubbleSort
    cout << "Print the time to sort SORTED DATA" << endl;
    double elapsed_mergeSort_SD = double(end_mergeSort_SD - start_mergeSort_SD) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort_SD = double(end_bubbleSort_SD - start_bubbleSort_SD) / CLOCKS_PER_SEC;
    double elapsed_minSort_SD = double(end_minSort_SD - start_minSort_SD) / CLOCKS_PER_SEC;
    cout << "MergeSort " << elapsed_mergeSort_SD << endl
         << "BubbleSort " << elapsed_bubbleSort_SD << endl
         << "SelectionSort " << elapsed_minSort_SD << endl << endl;


    // sort the three vectors using different algorithms and count the time
    // SI stands for sorted int
    clock_t start_bubbleSort_SI = clock();
    bubbleSort<int>(intV_B, intV_B.size());
    clock_t end_bubbleSort_SI = clock();

    clock_t start_minSort_SI = clock();
    minSort<int>(intV_S, intV_S.size());
    clock_t end_minSort_SI = clock();

    clock_t start_mergeSort_SI = clock();
    mergeSort<int>(intV_M, intTmp, 0, intV_M.size() - 1);
    clock_t end_mergeSort_SI = clock();

    // print elapsed time for mergeSort and bubbleSort
    cout << "Print the time to sort SORTED INTEGER" << endl;
    double elapsed_mergeSort_SI = double(end_mergeSort_SI - start_mergeSort_SI) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort_SI = double(end_bubbleSort_SI - start_bubbleSort_SI) / CLOCKS_PER_SEC;
    double elapsed_minSort_SI = double(end_minSort_SI - start_minSort_SI) / CLOCKS_PER_SEC;
    cout << "MergeSort " << elapsed_mergeSort_SI << endl
         << "BubbleSort " << elapsed_bubbleSort_SI << endl
         << "SelectionSort " << elapsed_minSort_SI << endl << endl;








    // code for debugging
    /*
    for (int i = 0; i < 1000; i++){
        cout << intV_B.at(i) << endl;
    }

    vector<int> v = {1, 3, 4, 5, 2};
    vector<char> u = {'a', 'b', 'z', 'e', 'f'};
    vector<string> z = {"za","ab", "fc", "cd", "xz"};
    vector<int> vTmp (5);
    vector<char> uTmp (5);
    vector<string> zTmp (5);

    bubbleSort<int>(v, 5);
    minSort<int> (v,5);
    mergeSort<int>(v, vTmp, 0, 4);

    bubbleSort<char>(u, 5);
    minSort<char> (u,5);
    mergeSort<char>(u, uTmp, 0, 4);

    bubbleSort<string>(z, 5);
    minSort<string> (z,5);
    mergeSort<string>(z, zTmp, 0, 4);

    for (int i = 0; i < 5; i++) {
        cout << z.at(i) << endl;
    }
     */
}