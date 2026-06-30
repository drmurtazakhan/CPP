/*
 * File name: CounterControlledWhileLoop.cpp
 * This program demonstrates a functional while loop.
 * Compile: g++ CounterControlledWhileLoop.cpp -o CounterControlledWhileLoop.exe
 * Run: ./CounterControlledWhileLoop.exe
 */

#include <iostream>
using namespace std;

int main()
{
    // counter is used to keep track of how many times the loop has executed.
    int counter = 0;

    int i = 0;
    // The loop body consists of everything between { and }
    while (i <= 20)
    {
        counter++;

        // These lines will execute as long as i is 20 or less
        cout << i << " ";

        // This is the update step (LCV). Without this, the loop
        // would run forever because i would always be 0.
        i = i + 5;
    }
    cout << endl;

    cout << "Outside the loop, i = " << i << endl;
    cout << "The loop executed " << counter << " times." << endl;

    return 0;
}