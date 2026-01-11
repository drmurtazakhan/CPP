#include <iostream>
using namespace std;

int main() {
    // Outer Block Variable
    int a = 100;
    cout << "Outer variable, a =  " << a << endl;

    { // START OF NESTED BLOCK
        // This variable is declared inside the block
        int b = 500; 
        
        // accessible from point of declaration to end of block
        cout << "Inside nested block, b = " << b << endl;
        
        // The inner block CAN see the outer variable
        cout << "Inside nested block, a is still: " << a << endl;
        
    } // END OF NESTED BLOCK

    // Error: b is no longer accessible here
    // cout << b; // This line would cause a compiler error

    cout << "Back in main, a is still: " << a << endl;

    return 0;
}