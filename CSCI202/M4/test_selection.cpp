// File name: test_selection.cpp
// How to compile: g++ test_selection.cpp -o test_selection.exe
// How to run: ./test_selection.exe

#include <iostream>
#include "searchSortAlgorithms.h" // Includes the selectionSort template

using namespace std;

int main() 
{
    // 1. Define an unsorted array of integers
    int myList[] = {34, 10, 56, 1, 89, 20};
    int size = 6;

    // 2. Display the array before sorting
    cout << "Array before Selection Sort: ";
    for(int i = 0; i < size; i++)
    {
        cout << myList[i] << " ";
    }
    cout << endl;

    // 3. Call selectionSort from searchSortAlgorithms.h
    // The algorithm will rearrange the elements in place
    selectionSort(myList, size);

    // 4. Display the array after sorting
    cout << "Array after Selection Sort:  ";
    for(int i = 0; i < size; i++)
    {
        cout << myList[i] << " ";
    }
    cout << endl;

    return 0;
}