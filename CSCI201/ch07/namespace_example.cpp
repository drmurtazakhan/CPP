// File Name: namespace_example.cpp
// Compile: g++ namespace_example.cpp -o namespace_example.exe
// Run: ./namespace_example.exe
// This program demonstrates the use of a namespace.

#include <iostream>
using namespace std;

// Define a namespace named school.
namespace school
{
    const int PASS_MARK = 60;

    void printMessage()
    {
        cout << "Welcome to CSCI 101!" << endl;
    }
}

int main()
{
    // Access namespace members using the scope resolution operator (::)
    cout << "Pass Mark: " << school::PASS_MARK << endl;

    school::printMessage();

    return 0;
}