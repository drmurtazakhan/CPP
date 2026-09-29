// compiler: g++ -std=c++17 runtime_error_example.cpp -o runtime_error_example.exe
// run: ./runtime_error_example.exe

// This example demonstrates how to handle runtime errors in C++ using the standard exception classes. In this case, we are specifically handling an overflow_error exception that occurs when a calculation exceeds the limit of the data type.

#include <iostream>
#include <stdexcept> // Required for runtime_error and overflow_error

using namespace std;

int main()
{
    try
    {
        // In a real scenario, this would be a calculation that
        // exceeds the limit of the data type.
        bool errorCondition = true;

        if (errorCondition)
        {
            throw overflow_error("The value is too large to be stored!");
        }
    }
    catch (const overflow_error &e)
    {
        // Using the what() function as mentioned in your slide
        cout << "Runtime Error Caught: " << e.what() << endl;
    }

    return 0;
}