// File name: test_bubble.cpp
// How to compile: g++ test_bubble.cpp -o test_bubble.exe
// How to run: ./test_bubble.exe

#include <iostream>
#include "searchSortAlgorithms.h" // Includes the bubbleSort template

using namespace std;

int main() 
{
    // 1. Define an unsorted array of integers
    int myList[] = {45, 23, 11, 89, 77, 98, 4, 28};
    int size = 8;

    // 2. Display the array before sorting
    cout << "Array before Bubble Sort: ";
    for(int i = 0; i < size; i++)
    {
        cout << myList[i] << " ";
    }
    cout << endl;

    // 3. Call bubbleSort from searchSortAlgorithms.h
    // This uses the swapElements helper function we corrected earlier
    bubbleSort(myList, size);

    // 4. Display the array after sorting
    cout << "Array after Bubble Sort:  ";
    for(int i = 0; i < size; i++)
    {
        cout << myList[i] << " ";
    }
    cout << endl;

    return 0;
}