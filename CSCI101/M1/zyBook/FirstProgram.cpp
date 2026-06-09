// FirstProgram.cpp
// Compile: g++ FirstProgram.cpp -o FirstProgram.exe
// Run: ./FirstProgram.exe
#include <iostream>
using namespace std;

int main()
{
    int wage; // Declare an integer variable

    wage = 20; // Assign value 20 to wage

    cout << "Salary is ";
    cout << wage * 40 * 52;
    cout << endl;

    return 0;
}
