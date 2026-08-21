// compile: g++  defaultValuesTest.cpp -o defaultValuesTest.exe
// run: ./defaultValuesTest.exe

#include <iostream>
using namespace std;
int main()
{
    // Using default values
    int c; // c is uninitialized
    cout << "The value of c (uninitialized) is: " << c << endl;

    char ch; // ch is uninitialized
    cout << "The value of ch (uninitialized) is: " << ch << endl;
    return 0;
}