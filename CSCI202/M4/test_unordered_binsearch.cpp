// Compile: g++ test_unordered_binsearch.cpp -o test_unordered_binsearch.exe
// Run: ./test_unordered_binsearch.exe

#include <iostream>
#include "unorderedArrayListType.h"

using namespace std;

int main()
{
    // 1. Start with an unsorted array of integers
    int values[] = {64, 12, 82, 5, 47, 25, 99, 33, 18, 51};
    int size = 10;

    unorderedArrayListType<int> myList(20);

    for (int i = 0; i < size; i++)
    {
        myList.insertEnd(values[i]);
    }

    cout << "Initial Unsorted List: ";
    myList.print();

    // 2. Sort the list before calling binSearch (which uses binarySearch)
    myList.sort();

    cout << "Sorted List:           ";
    myList.print();

    // 3. Prompt user and run binSearch
    int searchItem;
    cout << "Enter the number to search for: ";
    cin >> searchItem;

    int index = myList.binSearch(searchItem);

    if (index != -1)
        cout << "Item found at index: " << index << endl;
    else
        cout << "Item not found in the list." << endl;

    return 0;
}