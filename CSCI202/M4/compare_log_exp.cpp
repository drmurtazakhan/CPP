// File name: compare_log_exp.cpp
// How to compile: g++ compare_log_exp.cpp -o compare_log_exp.exe
// How to run: ./compare_log_exp.exe

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    int n;
    cout << "Enter a small value for n (suggested 5 to 28): ";
    cin >> n;

    // 1. Logarithmic Complexity O(log2 n)
    // This loop doubles the counter, reaching n very quickly.
    int logSteps = 0;
    for (int i = 1; i <= n; i = i * 2) 
    {
        logSteps++;
    }

    // 2. Exponential Complexity O(2^n)
    // This loop runs 2 raised to the power of n times.
    // We use a long long because the number gets huge very fast.
    long long expSteps = 0;
    long long limit = pow(2, n); // This defines how many times our loop must run

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