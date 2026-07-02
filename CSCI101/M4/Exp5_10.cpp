/*
 * File name: Exp5_10.cpp
 * compile: g++ Exp5_10.cpp -o Exp5_10.exe
 * run: ./Exp5_10.exe
 * This program shows why braces are critical for loop logic.
 */

#include <iostream>
using namespace std;

int main()
{
    // --- TOP EXAMPLE: Both lines repeat ---
    cout << "--- With braces: ---" << endl;
    for (int i = 1; i <= 5; i++)
    {
        cout << "Hello!" << endl; // Inside loop
        cout << "*" << endl;      // Inside loop
    }

    // --- BOTTOM EXAMPLE: Only the first line repeats ---
    cout << "\n--- Without braces: ---" << endl;
    for (int i = 1; i <= 5; i++)
        cout << "Hello!" << endl; // Only this is in the loop
    cout << "*" << endl;          // This runs only once AFTER the loop ends

    return 0;
}