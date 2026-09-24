// compile: g++ enum_variable_declaration.cpp -o enum_variable_declaration.exe
// run: ./enum_variable_declaration.exe

#include <iostream>
using namespace std;

int main()
{
    // Define the enumeration type and declare courseGrade at the same time.
    enum grades
    {
        A,
        B,
        C,
        D,
        F
    } courseGrade;

    // Assign a value to the enumeration variable.
    courseGrade = B;

    // Display the value of courseGrade.
    cout << "Course grade: " << courseGrade << endl;

    return 0;
}