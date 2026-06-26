/*
 * File name: nested_forloop.cpp
 * This program demonstrates how nested loops work to create a pattern.
 * compile: g++ nested_forloop.cpp -o nested_forloop.exe
 * run: ./nested_forloop.exe
 */

#include <iostream>
using namespace std;

int main()
{
    // The outer loop runs 5 times (i = 1 to 5)
    for (int i = 1; i <= 5; i++)
    {

        // The inner loop runs based on the current value of i
        // When i is 1, it runs once; when i is 5, it runs 5 times.
        for (int j = 1; j <= i; j++)
        {
            cout << "*"; // Prints the star without moving to a new line
        }

        // This moves the cursor to the next line after the inner loop finishes
        cout << endl;
    }

    return 0;
}