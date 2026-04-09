///Ch15_FibonacciNumber.cpp
// How to compile: g++ Ch15_FibonacciNumber.cpp -o Ch15_Fibonacci.exe
// How to run: ./Ch15_Fibonacci.exe
 
#include <iostream>
 
using namespace std;
 
int rFibNum(int n);

int main() 
{
    int nth;

    cout << "first five Fibonacci sequence: 0, 1, 1, 2, 3" << endl;
    cout << "Enter the position of the desired Fibonacci number: ";
    cin >> nth;
    cout << endl;

    cout << "The Fibonacci number at position " << nth 
         << " is: " << rFibNum(nth) << endl;

    return 0;
}

int rFibNum(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return rFibNum(n - 1) + rFibNum(n - 2);
}
