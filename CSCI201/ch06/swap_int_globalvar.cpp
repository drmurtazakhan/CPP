#include <iostream>
using namespace std;

// Global variables (declared outside any function)
int a = 10, b = 20;

// Swap function (Modified to use global variables directly)
void mySwap() {
    int c = a;
    a = b;
    b = c;
}

int main(){
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    
    mySwap(); // No arguments needed anymore
    
    cout << "After swap:  a = " << a << ", b = " << b << endl;
    return 0;
}