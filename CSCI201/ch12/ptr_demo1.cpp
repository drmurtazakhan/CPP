#include <iostream>
using namespace std;

int main() {
    // 1. Setup our variables
    int num1 = 100;          // A normal integer
    int* numptr = nullptr;   // A pointer (initialized to "nothing" for safety)

    // 2. Assign the address of num1 to the pointer
    numptr = &num1;

    // 3. Display the values
    cout << "1) num1 value: " << num1 << endl;         // Outputs: 100
    cout << "2) numptr address: " << numptr << endl;   // Outputs: 0x... (an address)
    cout << "3) Value at numptr: " << *numptr << endl; // Outputs: 100

    // 4. Change the value via the pointer
    *numptr = 200; 

    // 5. Check the result
    cout << "4) num1 after pointer change: " << num1 << endl; // Outputs: 200

    return 0;
}