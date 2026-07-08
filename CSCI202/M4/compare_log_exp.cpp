// File name: compare_log_exp.cpp
// How to compile: g++ compare_log_exp.cpp -o compare_log_exp.exe
// How to run: ./compare_log_exp.exe

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout << "Enter a value for n (suggested 32): ";
    cin >> n;

    // 1. Logarithmic Complexity O(log n)
    // This loop repeatedly divides the problem size by 2.
    long long logSteps = 0;
    for (long long i = n; i > 1; i /= 2)
    {
        logSteps++; // Example for n = 32: 32, 16, 8, 4, 2, 1
    }

    // 2. Exponential Complexity O(2^n)
    // This loop runs 2 raised to the power of n times.
    // We use long long because the number of iterations grows very quickly.
    long long expSteps = 0;
    long long limit = pow(2, n); // Total number of loop iterations

    cout << "...Calculating Exponential Loop (this may take a moment)..." << endl;

    for (long long i = 0; i < limit; i++)
    {
        expSteps++;
    }

    cout << "------------------------------------------" << endl;
    cout << "Results for n = " << n << endl;
    cout << "------------------------------------------" << endl;
    cout << "Logarithmic steps [O(log n)]:  " << logSteps << endl;
    cout << "Exponential steps [O(2^n)]:    " << expSteps << endl;
    cout << "------------------------------------------" << endl;

    return 0;
}