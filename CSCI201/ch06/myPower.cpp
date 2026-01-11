#include <iostream>
using namespace std;

// 1. Function Prototype
double myPower(double base, int exponent);

int main() {
    // Hard-coded values for testing
    double b = 2.0;
    int e = 3;

    // 2. Function Call
    double result = myPower(b, e);

    cout << b << " raised to the power of " << e << " is: " << result << endl;

    return 0;
}

// 3. Function Definition
double myPower(double base, int exponent) {
    double total = 1.0; // Start at 1
    
    // Loop 'exponent' number of times
    for (int i = 0; i < exponent; i++) {
        total = total * base; 
    }
    
    return total; // Send the final answer back to main
}