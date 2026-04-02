// Example file name: fibonacci_iterative.cpp

/*
   Commands to compile and run:
   g++ fibonacci_iterative.cpp -o fibonacci_iterative.exe
   ./fibonacci_iterative.exe
*/

#include <iostream>

using namespace std;

// Function to calculate the nth Fibonacci number iteratively
long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long first = 0;   // Represents (n-2)
    long long second = 1;  // Represents (n-1)
    long long current = 0;

    // Loop starts from the 2nd index up to n
    for (int i = 2; i <= n; i++) {
        current = first + second; 
        first = second;    // Move second to first for the next step
        second = current;  // Move current to second for the next step
    }

    return current;
}

int main() {
    int n;

    cout << "Enter the position (n) for Fibonacci sequence: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
    } else {
        cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << endl;
    }

    return 0;
}