// File name: test_insertion.cpp
// How to compile: g++ test_insertion.cpp -o test_insertion.exe
// How to run: ./test_insertion.exe

#include <iostream>
#include "searchSortAlgorithms.h" // Includes the insertionSort template

using namespace std;

int main() 
{
    // 1. Define an unsorted array of integers
    int myList[] = {25, 17, 31, 13, 2, 45, 9, 1};
    int size = 8;

    // 2. Display the array before sorting
    cout << "Array before Insertion Sort: ";
    for(int i = 0; i < size; i++)
    {
        cout << myList[i] << " ";
    }
    cout << endl;

    // 3. Call insertionSort from searchSortAlgorithms.h
    // This moves elements one by one to their correct position
    insertionSort(myList, size);

    // 4. Display the array after sorting
    cout << "Array after Insertion Sort:  ";
    for(int i = 0; i < size; i++)
    {
        cout << myList[i] << " ";
    }
    cout << endl;

    return 0;
}