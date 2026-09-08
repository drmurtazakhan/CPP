// ptr_demo1.cpp
// compile: g++ ptr_demo1.cpp -o ptr_demo1.exe
// run: ./ptr_demo1.exe
#include <iostream>
using namespace std;

int main()
{
    // Setup our variables
    int num1 = 100;        // A normal integer
    int *numptr = nullptr; // A pointer (initialized to "nothing" for safety)

    // Assign the address of num1 to the pointer
    numptr = &num1;

    // Display the values
    cout << "1) num1 value: " << num1 << endl;           // Outputs: 100
    cout << "2) num1 address: " << &num1 << endl;        // Outputs: 0x... (an address)
    cout << "3) numptr address: " << numptr << endl;     // Outputs: 0x... (an address)
    cout << "4) Value at numptr: " << *numptr << endl;   // Outputs: 100
    cout << "5) Address of numptr: " << &numptr << endl; // Outputs: 0x... (an address)

    // Change the value via the pointer
    *numptr = 200;

    // Check the result
    cout << "6) num1 after pointer change: " << num1 << endl; // Outputs: 200

    return 0;
}