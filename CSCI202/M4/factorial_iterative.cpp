// Example file name: factorial_iterative.cpp

// Compile: g++ factorial_iterative.cpp -o factorial_iterative.exe
// Run: ./factorial_iterative.exe


#include <iostream>

using namespace std;

// Function to calculate factorial iteratively
long long factorial(int n) {
    long long result = 1;

    // A loop that multiplies result by every number from 1 to n
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }

    return result;
}

int main() {
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << number << " is " << factorial(number) << endl;
    }

    return 0;
}