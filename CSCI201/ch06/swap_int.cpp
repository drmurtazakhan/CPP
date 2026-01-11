#include <iostream>
using namespace std;

// Swap function (Correct: Pass by Reference)
// It swaps the actual variables.
void mySwap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

int main(){
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    mySwap(a, b);
    cout << "After swap:  a = " << a << ", b = " << b << endl;
    return 0;
}

