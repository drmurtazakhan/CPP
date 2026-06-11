// Prog.cpp
// This program calculates the annual salary based on an hourly wage.
// Compile: g++ Prog1.cpp -o Prog1.exe
// Run: ./Prog1.exe

#include <iostream>
using namespace std;

int main()
{
    int wage; // Declare an integer variable

    wage = 20; // Assign value 20 to wage

    cout << "Salary is ";
    
    cout << wage * 4 * 52;
    
    cout << endl;

    return 0;
}