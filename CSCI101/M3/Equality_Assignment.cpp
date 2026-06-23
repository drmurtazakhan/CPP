// Equality_Assignment.cpp
// compile: g++ Equality_Assignment.cpp -o Equality_Assignment.exe
// run:     ./Equality_Assignment.exe
/*
    Program: Assignment Expression in an if Statement

    This program demonstrates a common programming mistake:
    using = instead of == in an if statement.

    =  : Assignment operator
    == : Equality operator
*/

#include <iostream>
using namespace std;

int main()
{
    int x = 10;

    cout << "Initial value of x = " << x << endl;

    // WARNING: This is an assignment, not a comparison!
    if (x = 5)
    {
        cout << "The value x is 5" << endl;
    }

    cout << "Value of x after the if statement = "
         << x << endl;

    return 0;
}