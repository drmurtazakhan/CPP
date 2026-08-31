// Exp_cin_get.cpp
// Compile: g++ Exp_cin_get.cpp -o Exp_cin_get.exe
// Run: ./Exp_cin_get.exe

// Example: Extraction operator behavior vs. get() function

#include <iostream>

using namespace std;

int main()
{
    char ch1, ch2;
    int num;

    // --- Part 1: Demonstration of >> skipping whitespace ---
    cout << "Enter 'A 25': ";
    // With input "A 25":
    // 'A' goes to ch1. The blank is skipped.
    // '2' goes to ch2. '5' goes to num.
    cin >> ch1 >> ch2 >> num;

    cout << "\nExtraction Operator (>>) Results:" << endl;
    cout << "ch1: " << ch1 << endl; // Stores 'A'
    cout << "ch2: " << ch2 << endl; // Stores '2' (not the blank!)
    cout << "num: " << num << endl; // Stores 5

    // Clear the remaining input buffer so we can try the next part cleanly
    cin.ignore(100, '\n');

    // --- Part 2: Using get() to capture whitespace ---
    cout << "\n-----------------------------" << endl;
    cout << "Enter 'A 25' again: ";

    // Using cin.get() to read exactly what is in the buffer
    cin.get(ch1); // Reads 'A'
    cin.get(ch2); // Reads the blank space!
    cin >> num;   // Reads 25

    cout << "\nget() Function Results:" << endl;
    cout << "ch1: " << ch1 << endl;
    // We can check if it is a space using (int) casting
    cout << "ch2 is a space: " << (ch2 == ' ') << endl;
    cout << "num: " << num << endl;

    return 0;
}