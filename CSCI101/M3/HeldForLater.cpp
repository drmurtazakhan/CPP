// HeldForLater.cpp
// compile: g++ HeldForLater.cpp -o HeldForLater.exe
// run:     ./HeldForLater.exe
// Demonstration of "held for later input"

#include <iostream>
using namespace std;

int main()
{
    char ch;

    cout << "Enter AB: ";
    cin >> ch;

    cout << "The value stored in ch is: " << ch << endl;
    cout << "The character 'B' is held for later input." << endl;

    // Read the next character from the input buffer
    cin >> ch;

    cout << "The next input operation reads: " << ch << endl;

    return 0;
}