//  testStringCopy.cpp
/*
   HOW TO COMPILE AND RUN (PowerShell):
   1. Compile: g++ testStringCopy.cpp -o testStringCopy.exe -mconsole
   2. Run:     .\testStringCopy.exe
*/

#include <iostream>
#include <string>
#include "myStack.h"

using namespace std;

int main() 
{
    // 1. Create the original stack with capacity for 10 strings
    stackType<string> stack1(10);
    stack1.initializeStack();

    // 2. Insert (push) objects into the first stack
    cout << "Pushing to stack1: Ivy, Tech, College" << endl;
    stack1.push("Ivy");
    stack1.push("Tech");
    stack1.push("College");

    // 3. Use the Copy Constructor to create stack2 as a copy of stack1
    // This calls: stackType(const stackType<Type>& otherStack)
    stackType<string> stack2(stack1); 

    cout << "Success: stack2 created using copy constructor." << endl;

    // 4. Verify the contents of stack2 (should be same as stack1)
    cout << "The top of stack2 is: " << stack2.top() << endl; // Should be "College"

    // 5. Demonstrate that they are independent (Deep Copy)
    cout << "Popping from stack2..." << endl;
    stack2.pop();
    
    cout << "Now, stack2 top is: " << stack2.top() << endl;   // Should be "Tech"
    cout << "But stack1 top is still: " << stack1.top() << endl; // Should still be "College"

    return 0;
}