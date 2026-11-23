// File name: test_binarysearch.cpp
// Compile: g++ test_binarysearch.cpp -o test_binarysearch.exe
// Run: ./test_binarysearch.exe

#include <iostream>
#include "searchSortAlgorithms.h"

using namespace std;

int main()
{
    // 1. Start with an unsorted array of integers
    int myList[] = {64, 12, 82, 5, 47, 25, 99, 33, 18, 51};
    int size = 10;
    int searchItem;

    cout << "Initial Unsorted List: ";
    for (int i = 0; i < size; i++)
        cout << myList[i] << " ";
    cout << endl;

    // 2. Sort the array first (binarySearch requires sorted data)
    selectionSort(myList, size);

    cout << "Sorted List:           ";
    for (int i = 0; i < size; i++)
        cout << myList[i] << " ";
    cout << endl;

    // 3. Prompt user and run binarySearch
    cout << "Enter the number to search for: ";
    cin >> searchItem;

    int index = binarySearch(myList, size, searchItem);

    if (index != -1)
        cout << "Item found at index: " << index << endl;
    else
        cout << "Item not found in the list." << endl;

    return 0;
}