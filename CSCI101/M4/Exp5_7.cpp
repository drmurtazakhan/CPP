/*
 * File name: Exp5_7.cpp
 * Compile: g++ Exp5_7.cpp -o Exp5_7.exe
 * Run: ./Exp5_7.exe
 * This program demonstrates an EOF-controlled while loop
 * to calculate the sum of a set of numbers.
 */

#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int num;

    // Read the first number before the loop
    cout << "Enter numbers to sum (use EOF/Ctrl+Z or Ctrl+D to stop):" << endl;
    cin >> num;

    // The condition (cin) checks if the last input operation was successful.
    // If EOF is reached, cin becomes false, and the loop terminates.
    while (cin)
    {
        sum = sum + num; // Add the current number to the running total

        cin >> num; // Get the next number
    }

    cout << "Sum = " << sum << endl;

    return 0;
}