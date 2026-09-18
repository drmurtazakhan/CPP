// swap_int.cpp
// compile: g++ swap_int.cpp -o swap_int.exe
// run: ./swap_int.exe
#include <iostream>
using namespace std;

// Swap function (Correct: Pass by Reference)
// It swaps the actual variables.
void mySwap(int &a, int &b)
{
    int c = a; // temporary variable to hold the value of a
    a = b;
    b = c;
}

int main()
{
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    mySwap(x, y);
    cout << "After swap:  x = " << x << ", y = " << y << endl;
    return 0;
}
