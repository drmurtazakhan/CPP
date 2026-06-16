// Exp_pow_sqrt.cpp
// Compile: g++ Exp_pow_sqrt.cpp -o Exp_pow_sqrt.exe
// Run: ./Exp_pow_sqrt.exe

#include <iostream>
#include <cmath> // Required for pow() and sqrt()

using namespace std;

int main()
{
    // pow(base, exponent) calculates the power
    double powerResult = pow(2, 3);

    // sqrt(number) calculates the square root
    double sqrtResult = sqrt(16);

    cout << "2 raised to the power of 3 is: " << powerResult << endl;
    cout << "The square root of 16 is: " << sqrtResult << endl;

    return 0;
}