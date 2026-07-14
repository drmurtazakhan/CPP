// File Name: test_typedef.cpp
// Compile: g++ test_typedef.cpp -o test_typedef.exe
// Run: ./test_typedef.exe
// This program demonstrates the use of typedef in C++.

#include <iostream>
using namespace std;

int main()
{
    // typedef creates an alias (another name) for an existing data type.
    // It does NOT create a new data type.

    // Create an alias "integer" for int.
    typedef int integer;

    // Declare a variable using the new type name.
    integer age;

    age = 20;

    cout << "Age: " << age << endl;

        return 0;
}