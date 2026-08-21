// compile: g++ PrePostIncrement.cpp -o PrePostIncrement.exe
// run: ./PrePostIncrement.exe
#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;

    // --- CASE 1: Pre-Increment (++a) ---
    // Rule: Increment FIRST, then use the new value in the calculation.
    a = 5;
    b = ++a;

    // Step-by-step breakdown:
    // 1. 'a' turns from 5 into 6 immediately.
    // 2. The math becomes: b = 6;

    cout << "--- Case 1 (Pre-Increment) ---" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
    cout << endl;

    // --- CASE 2: Post-Increment (a++) ---
    // Rule: Use the CURRENT value in the calculation first, then increment 'a' AFTERWARDS.
    a = 5; // Resetting 'a' back to 5
    b = a++;

    // Step-by-step breakdown:
    // 1. The math uses the current value of 'a' (which is 5): b = 5;
    // 2. 'b' becomes 5.
    // 3. Now that the line is done evaluating, 'a' secretly bumps up from 5 to 6.

    cout << "--- Case 2 (Post-Increment) ---" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;

    return 0;
}