#include <iostream>
using namespace std;

// 1. SPECIFY DEFAULT PARAMETERS IN PROTOTYPE
// 'times' is a default parameter. If the user doesn't provide it, it defaults to 1.
void printMessage(string msg, int times = 1);

int main() {
    // 2. SAME NUMBER OF PARAMETERS
    // Here we provide both: actual parameters (2) match formal parameters (2).
    printMessage("Hello!", 3);

    // 3. RELAXED CONDITION (Using Default)
    // Here we only provide 1 actual parameter. 
    // Since 'times' has a default value, C++ allows this!
    printMessage("Welcome!"); 

    return 0;
}

// Function definition
void printMessage(string msg, int times) {
    for(int i = 0; i < times; i++) {
        cout << msg << endl;
    }
}