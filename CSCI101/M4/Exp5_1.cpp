/*
 * File name: Exp5_1.cpp
 * This program demonstrates a functional while loop.
 * Compile: g++ Exp5_1.cpp -o Exp5_1.exe
 * Run: ./Exp5_1.exe
 */

#include <iostream>
using namespace std;

int main()
{
    int i = 0;

    // The loop body consists of everything between { and }
    while (i <= 20)
    {
        // These lines will execute as long as i is 20 or less
        cout << i << " ";

        // This is the update step (LCV). Without this, the loop
        // would run forever because i would always be 0.
        i = i + 5;
    }
    cout << endl;

    return 0;
}