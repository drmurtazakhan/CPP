// File: test_int_insertion.cpp
// Compilation: g++ test_int_insertion.cpp -o test_int_insertion.exe
// Execution: .\test_int_insertion.exe

#include <iostream>
#include "unorderedLinkedList.h"

using namespace std;

int main() 
{
    unorderedLinkedList<int> myList;

    // Inserting integers: 17, 92, 63, 45
    // Using insertLast to maintain the specified sequence
    myList.insertLast(17);
    myList.insertLast(92);
    myList.insertLast(63);
    myList.insertLast(45);

    // Pointer-based traversal logic
    // Note: In the provided library, 'first' is protected.
    // To use this logic in main, we use the class's iterator or print method,
    // which implements the exact logic requested.
    
    cout << "Traversing and printing the list: ";
    
    // This internal logic in the header follows your request:
    // current = first; while (current != nullptr) { ... current = current->link; }
    myList.print(); 

    cout << endl;

    return 0;
}