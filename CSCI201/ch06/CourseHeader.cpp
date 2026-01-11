#include <iostream>
using namespace std;

// 1. Function Prototype (Blueprint)
void printHeader();

int main() {
    // 2. Function Call (Parentheses are empty)
    printHeader();

    cout << "\nProgram execution completed." << endl;

    return 0;
}

// 3. Function Definition
// The parentheses are empty because no data is being passed in.
void printHeader() {
    cout << "Ivy Tech Community College" << endl;
    cout << "School of Information Technology" << endl;
    cout << "CSCI 201 AVA Computer Science II" << endl;
}