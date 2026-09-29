// compiler: g++ -std=c++17 logic_error_example.cpp -o logic_error_example.exe
// run: ./logic_error_example.exe

// This example demonstrates how to handle logic errors in C++ using the standard exception classes. In this case, we are specifically handling an out_of_range exception that occurs when trying to access an invalid index of a string.

#include <iostream>
#include <string>
#include <stdexcept> // Required for logic_error and out_of_range

using namespace std;

int main()
{
    string phrase = "C++ Class";

    try
    {
        // The string only has indices 0-8.
        // Accessing index 20 will trigger an out_of_range exception.
        cout << "Character at index 20: " << phrase.at(20) << endl;
    }
    catch (const out_of_range &e)
    {
        cout << endl;
        // e.what() returns the standard error message for this class
        cout << "Logic Error Caught: " << e.what() << endl;
    }

    return 0;
}