// compile: g++ -std=c++17 linkedList_print_revPrint.cpp -o linkedList_print_revPrint.exe

// run: .\linkedList_print_revPrint.exe

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
    
        
    // This internal logic in the header follows your request:
    // current = first; while (current != nullptr) { ... current = current->link; }
    cout << "Print in order: ";
    myList.print(); 

    cout << endl;

    cout << "Print in reverse order: ";
    myList.reversePrint(); // Call the public wrapper function for reverse printing

    cout << endl;

    return 0;
}