// fibonacci_iterative.cpp
// How to compile: g++ fibonacci_iterative.cpp -o fibonacci_iterative.exe
// How to run: ./fibonacci_iterative.exe
#include <iostream>

using namespace std;

int iFibNum(int n);

int main()
{
    int nth;

    cout << "first five Fibonacci sequence: 0, 1, 1, 2, 3" << endl;
    cout << "Enter the position of the desired Fibonacci number: ";
    cin >> nth;
    cout << endl;

    cout << "The Fibonacci number at position " << nth
         << " is: " << iFibNum(nth) << endl;

    return 0;
}

// Iterative version of the Fibonacci function
int iFibNum(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    int first = 0;   // Represents (n-2)
    int second = 1;  // Represents (n-1)
    int current = 0;

    // Start loop from 3 since we handled positions 1 and 2 above
    for (int i = 3; i <= n; i++)
    {
        current = first + second;
        first = second;  // Move second to first for next iteration
        second = current; // Move current to second for next iteration
    }

    return current;
}