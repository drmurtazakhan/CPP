// Compilation: g++ -std=c++17 doublyLinkedList_print_revPrint.cpp -o doublyLinkedList_print_revPrint.exe

// Execution: .\doublyLinkedList_print_revPrint.exe

#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int main() 
{
    doublyLinkedList<int> myList;

    // Inserting integers: 17, 92, 63, 45
    // Note: doublyLinkedList insert() automatically maintains ascending order.
    myList.insert(17);
    myList.insert(92);
    myList.insert(63);
    myList.insert(45);

    cout << "Print in order (forward): ";
    myList.print();
    cout << endl;

    cout << "Print in reverse order: ";
    myList.reversePrint();
    cout << endl;

    return 0;
}