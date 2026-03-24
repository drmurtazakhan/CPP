// File: test_search_unorderlist.cpp
// Compilation: g++ test_search_unorderlist.cpp -o test_search_unorderlist.exe
// Execution: .\test_search_unorderlist.exe

#include <iostream>
#include "unorderedLinkedList.h"

using namespace std;

int main() 
{
    // Initialize the list object
    unorderedLinkedList<int> myList;
    int searchNum;

    // 1. Build the list: 17 -> 92 -> 63 -> 45
    // insertLast adds the new node to the end of the current chain.
    myList.insertLast(17);
    myList.insertLast(92);
    myList.insertLast(63);
    myList.insertLast(45);

    // 2. Display the list contents
    cout << "Current List: ";
    myList.print();
    cout << endl << "------------------------------------" << endl;

    // 3. Test Case: Searching for an item that exists
    searchNum = 63;
    cout << "Action: Searching for " << searchNum << "..." << endl;
    
    // The search function returns a boolean (true/false)
    if (myList.search(searchNum))
    {
        cout << "Result: " << searchNum << " was found in the list." << endl;
    }
    else
    {
        cout << "Result: " << searchNum << " was NOT found." << endl;
    }

    // 4. Test Case: Searching for an item that does NOT exist
    searchNum = 100;
    cout << endl << "Action: Searching for " << searchNum << "..." << endl;
    
    if (myList.search(searchNum))
    {
        cout << "Result: " << searchNum << " was found in the list." << endl;
    }
    else
    {
        cout << "Result: " << searchNum << " was NOT found." << endl;
    }

    return 0;
}