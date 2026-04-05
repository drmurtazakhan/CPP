// File name: test_merge.cpp
// How to compile: g++ test_merge.cpp -o test_merge.exe
// How to run: ./test_merge.exe

#include <iostream>
#include "searchSortAlgorithms.h" // Includes the mergeSort template

using namespace std;

int main() 
{
    // 1. Define an unsorted array of integers
    int myList[] = {35, 28, 18, 45, 62, 48, 30, 38};
    int size = 8;

    // 2. Display the array before sorting
    cout << "Array before Merge Sort: ";
    for(int i = 0; i < size; i++)
    {
        cout << myList[i] << " ";
    }
    cout << endl;

    // 3. Call mergeSort from searchSortAlgorithms.h
    // This calls recMergeSort and the merge function internally
    mergeSort(myList, size);

    // 4. Display the array after sorting
    cout << "Array after Merge Sort:  ";
    for(int i = 0; i < size; i++)
    {
        cout << myList[i] << " ";
    }
    cout << endl;

    return 0;
}