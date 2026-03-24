// File: test_search_orderedlist.cpp
// Compilation: g++ test_search_orderedlist.cpp -o test_search_orderedlist.exe
// Execution: .\test_search_orderedlist.exe

#include <iostream>
#include "orderedLinkedList.h"

using namespace std;

int main() 
{
    // Create an instance of the ordered linked list for integers
    orderedLinkedList<int> myList;
    int searchNum;

    // 1. Insert integers into the list: 17, 92, 63, 45
    // In an ordered list, the insert function automatically finds 
    // the correct numerical position to keep the list sorted.
    myList.insert(17);
    myList.insert(92);
    myList.insert(63);
    myList.insert(45);

    // 2. Print the list to verify it is sorted (Expected: 17 45 63 92)
    cout << "Current Ordered List Contents: ";
    myList.print(); 
    cout << endl << "------------------------------------" << endl;

    // 3. Search for an item that is present in the list
    searchNum = 63;
    cout << "Action: Searching for " << searchNum << "..." << endl;
    
    if (myList.search(searchNum))
    {
        cout << "Result: " << searchNum << " was found in the list." << endl;
    }
    else
    {
        cout << "Result: " << searchNum << " was NOT found in the list." << endl;
    }

    // 4. Search for an item that is NOT present in the list
    searchNum = 100;
    cout << endl << "Action: Searching for " << searchNum << "..." << endl;
    
    if (myList.search(searchNum))
    {
        cout << "Result: " << searchNum << " was found in the list." << endl;
    }
    else
    {
        cout << "Result: " << searchNum << " was NOT found in the list." << endl;
    }

    return 0;
}