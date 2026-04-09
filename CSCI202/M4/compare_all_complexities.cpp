// File name: compare_all_complexities.cpp
// How to compile: g++ compare_all_complexities.cpp -o compare_all_complexities.exe
// How to run: ./compare_all_complexities.exe

#include <iostream>
#include <cmath>
#include <iomanip> // For clean table formatting

using namespace std;

int main() 
{
    int n;
    cout << "Enter a value for n (try 10, 20, or 25): ";
    cin >> n;

    // 1. Logarithmic: O(log2 n)
    long long logSteps = 0;
    for (long long i = 1; i <= n; i *= 2) {
        logSteps++;
    }

    // 2. Linear: O(n)
    long long linearSteps = 0;
    for (long long i = 0; i < n; i++) {
        linearSteps++;
    }

    // 3. Linearithmic: O(n log n)
    long long nLogNSteps = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 1; j <= n; j *= 2) {
            nLogNSteps++;
        }
    }

    // 4. Quadratic: O(n^2)
    long long quadraticSteps = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            quadraticSteps++;
        }
    }

    // 5. Exponential: O(2^n)
    long long exponentialSteps = 0;
    long long expLimit = pow(2, n);
    
    // Safety check: Don't run the actual loop if n is too high
    if (n <= 60) {
        for (long long i = 0; i < expLimit; i++) {
            exponentialSteps++;
        }
    } else {
        exponentialSteps = expLimit; // Just use the math if it's too slow to loop
    }

    // Display the results in a table
    cout << "\nComparison Table for n = " << n << endl;
    cout << "------------------------------------------------" << endl;
    cout << left << setw(20) << "Complexity" << "Actual Steps Counted" << endl;
    cout << "------------------------------------------------" << endl;
    cout << setw(20) << "O(log n)" << logSteps << endl;
    cout << setw(20) << "O(n)" << linearSteps << endl;
    cout << setw(20) << "O(n log n)" << nLogNSteps << endl;
    cout << setw(20) << "O(n^2)" << quadraticSteps << endl;
    cout << setw(20) << "O(2^n)" << exponentialSteps << endl;
    cout << "------------------------------------------------" << endl;

    return 0;
}