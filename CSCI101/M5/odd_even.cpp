// compile: g++ odd_even.cpp -o odd_even.exe
// run: ./odd_even.exe
// Program to check whether a number is odd or even

#include <iostream>
using namespace std;

int main()
{
    int number;

    // Input
    cout << "Enter an integer: ";
    cin >> number;

    // Check odd or even
    if (number % 2 == 0)
        cout << number << " is Even." << endl;
    else
        cout << number << " is Odd." << endl;

    return 0;
}