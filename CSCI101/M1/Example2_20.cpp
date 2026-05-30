// Example2_20.cpp
// compile: g++ Example2_20.cpp -o Example2_20.exe
// run:     ./Example2_20.exe
#include <iostream>
using namespace std;

int main() {
    int a;
    int b;

    // --- CASE 1: Pre-Increment (++a) ---
    // Rule: Increment FIRST, then use the new value in the calculation.
    a = 5; 
    b = 2 + (++a); 
    
    // Step-by-step breakdown:
    // 1. 'a' turns from 5 into 6 immediately.
    // 2. The math becomes: b = 2 + 6;
    // 3. 'b' becomes 8.
    
    cout << "--- Case 1 (Pre-Increment) ---" << endl;
    cout << "Value of a: " << a << " (Expected: 6)" << endl;
    cout << "Value of b: " << b << " (Expected: 8)" << endl;
    cout << endl;


    // --- CASE 2: Post-Increment (a++) ---
    // Rule: Use the CURRENT value in the calculation first, then increment 'a' AFTERWARDS.
    a = 5; // Resetting 'a' back to 5
    b = 2 + (a++); 
    
    // Step-by-step breakdown:
    // 1. The math uses the current value of 'a' (which is 5): b = 2 + 5;
    // 2. 'b' becomes 7.
    // 3. Now that the line is done evaluating, 'a' secretly bumps up from 5 to 6.
    
    cout << "--- Case 2 (Post-Increment) ---" << endl;
    cout << "Value of a: " << a << " (Expected: 6)" << endl;
    cout << "Value of b: " << b << " (Expected: 7)" << endl;

    return 0;
}