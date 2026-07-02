/*
 * File name: CounterControlledWhileLoop.cpp
 * Compile: g++ CounterControlledWhileLoop.cpp -o CounterControlledWhileLoop.exe
 * Run: ./CounterControlledWhileLoop.exe
 */

#include <iostream>
using namespace std;

int main()
{
    // 1. Initialization: Set the counter to start at 0
    int counter = 0;
    int N = 5; // We want to execute the loop exactly 5 times

    // 2. Testing: The loop continues as long as counter is less than N
    while (counter <= N)
    {
        cout << "Executing loop iteration " << counter + 1 << endl;

        // 3. Updating: Increment the counter so we eventually reach N
        counter++;
    }

    cout << "Outside loop value of Counter = " << counter << endl;
    return 0;
}