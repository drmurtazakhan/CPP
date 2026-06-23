// Exp1_setw.cpp
// Compile: g++ Exp1_setw.cpp -o Exp1_setw.exe
// Run: ./Exp1_setw.exe
#include <iostream>
#include <iomanip> // Required for setw

using namespace std;

int main()
{
    int x = 42;

    // setw(5) means the output will take up 5 columns (minimum width = 5)
    // Since "42" uses only 2 characters, the remaining space (3 columns)
    // will be filled with spaces on the LEFT (right-justified output)

    cout << "Without setw: " << x << endl;

    cout << "With setw(5):  " << setw(5) << x << endl;

    // You can see the difference more clearly with multiple numbers
    int a = 7, b = 123, c = 9999, d = 1234567;

    cout << "\nTable-style output using setw:\n";

    cout << setw(5) << a << endl; // prints 7 right-justified in width 5
    cout << setw(5) << b << endl; // prints 123 right-justified in width 5
    cout << setw(5) << c << endl; // prints 9999 (already takes 4 spaces)
    cout << setw(5) << d << endl; // prints 1234567 (takes 7 spaces)
    return 0;
}