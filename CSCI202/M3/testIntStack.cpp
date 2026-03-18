// testIntStack.cpp
/*
   HOW TO COMPILE AND RUN (PowerShell):
   1. Compile: g++ testIntStack.cpp -o testIntStack.exe -mconsole
   2. Run:     .\testIntStack.exe
*/

#include <iostream>
#include "myStack.h" // Includes both the ADT and the implementation

using namespace std;

int main() 
{
    // Create a stack that can hold up to 5 integers
    // stackTop is initialized to 0 and an array is created
    stackType<int> myStack(5); 

    cout << "Step 1: Adding numbers to the stack..." << endl;
    
    // push(10) puts 10 at index 0, then stackTop becomes 1
    myStack.push(10); 
    // push(20) puts 20 at index 1, then stackTop becomes 2
    myStack.push(20); 
    // push(30) puts 30 at index 2, then stackTop becomes 3
    myStack.push(30); 

    // The top element is always at (stackTop - 1)
    cout << "The number at the top is: " << myStack.top() << endl; // Should be 30

    cout << "Step 2: Removing the top element..." << endl;
    myStack.pop(); // Decrements stackTop to 2

    cout << "The new number at the top is: " << myStack.top() << endl; // Should be 20

    // Final check on stack status
    if (myStack.isEmptyStack()) 
        cout << "The stack is empty." << endl;
    else
        cout << "The stack still contains elements." << endl;

    return 0;
}