// Compilation: g++ test_doublyLinkedList.cpp -o test_doublyLinkedList.exe
// Execution: .\test_doublyLinkedList.exe

#include <iostream>
#include "doublyLinkedList.h" //[cite: 5]

using namespace std;

int main() 
{
    // 1. Initialize an empty doubly linked list for integers
    doublyLinkedList<int> myList; 

    // 2. Insert elements (Note: doublyLinkedList's insert function automatically sorts them in ascending order)
    myList.insert(45); 
    myList.insert(17); 
    myList.insert(92); 
    myList.insert(63); 

    cout << "--- Basic Operations Demonstration ---" << endl;
    
    // Forward print using the 'next' pointers
    cout << "Forward Print: ";
    myList.print(); //[cite: 5]
    cout << endl;

    // Reverse print using the 'back' pointers
    cout << "Reverse Print: ";
    myList.reversePrint(); //[cite: 5]
    cout << endl;

    // Check metadata and boundaries
    cout << "List Length: " << myList.length() << endl; //[cite: 5]
    cout << "Front Element: " << myList.front() << endl; //[cite: 5]
    cout << "Back Element: " << myList.back() << endl;   //[cite: 5]

    // 3. Demonstrate search operation
    int searchVal = 63;
    cout << "\n--- Search Operation ---" << endl;
    if (myList.search(searchVal)) { //[cite: 5]
        cout << searchVal << " was found in the list." << endl;
    } else {
        cout << searchVal << " was NOT found in the list." << endl;
    }

    // 4. Demonstrate node deletion
    cout << "\n--- Delete Operation ---" << endl;
    cout << "Deleting 63 from the list..." << endl;
    myList.deleteNode(63); //[cite: 5]

    cout << "Forward Print after deletion: ";
    myList.print(); 
    cout << endl;
    
    cout << "New List Length: " << myList.length() << endl; 

    return 0;
}