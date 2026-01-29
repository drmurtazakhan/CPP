#include <iostream>
using namespace std;

int main() {
    // 1. Declare a standard integer variable
    int x = 10;

    // 2. Create an alias (reference) named 'y' for 'x'
    // This does NOT create a new memory location for y.
    int &y = x; 

    cout << "Initial values:" << endl;
    cout << "x = " << x << ", y (alias) = " << y << endl;

    // 3. Update using the alias
    y = 25; 
    cout << "\nAfter setting y = 25:" << endl;
    cout << "x = " << x << " (x changed because y is its nickname!)" << endl;

    // 4. Update using the original name
    x = 2 * x + 30; 
    cout << "\nAfter calculating x = 2 * x + 30:" << endl;
    cout << "x = " << x << ", y = " << y << " (y follows x perfectly)" << endl;

    // 5. Proof: Both share the exact same memory address
    cout << "\nMemory Address Check:" << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Address of y: " << &y << endl;

    return 0;
}