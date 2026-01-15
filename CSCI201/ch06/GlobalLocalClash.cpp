#include <iostream>
using namespace std;

// 1. GLOBAL VARIABLE
int a = 100; 

void showVariableClash() {
    // 2. LOCAL VARIABLE (Same name!)
    int a = 20; 

    cout << "The Local 'a' is:  " << a << endl;   // Accesses the local 20
    
    // 3. Using SCOPE RESOLUTION OPERATOR (::)
    cout << "The Global 'a' is: " << ::a << endl; // Accesses the global 100
}

int main() {
    showVariableClash();
    return 0;
}