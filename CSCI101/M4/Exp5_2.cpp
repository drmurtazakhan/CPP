/*
 * File name: Exp5_2.cpp
 * This program demonstrates how a while loop behaves when the
 * condition is false initially.
 * Compile: g++ Exp5_2.cpp -o Exp5_2.exe
 * Run: ./Exp5_2.exe
 */

#include <iostream>

using namespace std;

int main()
{
    int i = 20;

    // The condition (i < 20) is checked first.
    // Since 20 is not less than 20, the condition is false.
    // The entire body of the loop is skipped.
    while (i < 20)
    {
        cout << i << " ";
        i = i + 5;
    }

    // This line will execute, but nothing will have been printed by the loop.
    cout << endl
         << "The loop did not execute because the condition was false." << endl;

    return 0;
}