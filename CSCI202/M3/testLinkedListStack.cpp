// testLinkedListStack.cpp
/*
   HOW TO COMPILE AND RUN (PowerShell):
   1. Compile: g++ testLinkedListStack.cpp -o testLinkedListStack.exe -mconsole
   2. Run:     .\testLinkedListStack.exe
*/

#include <iostream>
#include "linkedStack.h" // Includes the linked list stack implementation

using namespace std;

int main() 
{
    // Create a stack for integers. 
    // Notice we don't pass a size (like 10 or 50) because it's a linked list.
    linkedStackType<int> stack; 

    // Initialize the stack
    stack.initializeStack();

    cout << "--- Linked List Stack Test ---" << endl;

    // Adding elements
    cout << "Pushing: 50, 100, 150" << endl;
    stack.push(50);
    stack.push(100);
    stack.push(150);

    // Show the top element (should be 150)
    if (!stack.isEmptyStack())
        cout << "Current top element: " << stack.top() << endl;

    // Remove the top element
    cout << "Popping the top element..." << endl;
    stack.pop();

    // Show the new top (should be 100)
    cout << "New top element after pop: " << stack.top() << endl;

    // Check stack status
    if (stack.isFullStack())
        cout << "The stack is full." << endl;
    else
        cout << "The stack is not full (linked stacks are almost never 'full')." << endl;

    return 0;
}