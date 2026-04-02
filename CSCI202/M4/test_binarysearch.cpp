// File name: test_binarysearch.cpp
// How to compile: g++ test_binarysearch.cpp -o test_binarysearch.exe
// How to run: ./test_binarysearch.exe

#include <iostream>
#include "searchSortAlgorithms.h" // Includes the provided binarySearch template

using namespace std;

int main() 
{
    // Binary search requires a sorted list
    int myList[] = {5, 12, 25, 33, 47, 51, 64, 78, 82, 99};
    int size = 10;
    int searchItem;

    cout << "Current Sorted List: ";
    for(int i = 0; i < size; i++)
        cout << myList[i] << " ";
    cout << endl;

    cout << "Enter the number to search for: ";
    cin >> searchItem;

    // The binarySearch function is called from searchSortAlgorithms.h
    // It returns the index of the item, or -1 if not found
    int index = binarySearch(myList, size, searchItem);

    if (index != -1)
        cout << "Item found at index: " << index << endl;
    else
        cout << "Item not found in the list." << endl;

    return 0;
}