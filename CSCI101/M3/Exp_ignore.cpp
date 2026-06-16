// Exp_ignore.cpp
// Compile: g++ Exp_ignore.cpp -o Exp_ignore.exe
// Run: ./Exp_ignore.exe

// Example: Using the ignore() function
#include <iostream>

using namespace std;

int main()
{
    int a, b;

    /*
       Input provided in the console during execution:
       25 67 89 43 72
       12 78 34
    */

    cout << "Enter the numbers (two lines): " << endl;

    // 1. First extraction:
    // This reads '25' and stores it in variable 'a'.
    // The input pointer is now sitting right after '25'.
    cin >> a;

    // 2. Using ignore():
    // cin.ignore(100, '\n');
    // '100' is the maximum number of characters to skip.
    // '\n' is the delimiter; it stops ignoring once it hits the newline character.
    // This effectively discards ' 67 89 43 72' and moves the pointer
    // to the beginning of the next line.
    cin.ignore(100, '\n');

    // 3. Second extraction:
    // Because the previous line was ignored, 'b' now receives '12'
    // from the start of the second line.
    cin >> b;

    cout << "\nResults:" << endl;
    cout << "a = " << a << endl; // Should be 25
    cout << "b = " << b << endl; // Should be 12

    return 0;
}