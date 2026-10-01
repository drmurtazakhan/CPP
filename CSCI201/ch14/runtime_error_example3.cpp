// compile: g++ -std=c++17 runtime_error_example3.cpp -o runtime_error_example3.exe
// run: ./runtime_error_example3.exe

#include <iostream>
#include <stdexcept> // Required for runtime_error and overflow_error
#include <limits>    // Required to check numeric limits

using namespace std;

int main()
{
    // Test Case 1: Value less than maximum allowed (Normal Case)
    // int current_value = 2147483640;

    // Test Case 2: Value greater than maximum allowed (Overflow Case)
    // Uncomment the line below (and comment the line above) to test exception throwing
    long long current_value = 2147483648LL;

    cout << "Current Value: " << current_value << endl;

    try
    {
        if (current_value < numeric_limits<int>::max())
        {
            cout << "Ok: Value is within allowed range." << endl;
        }
        else
        {
            throw overflow_error("Overflow Error: The value exceeds the maximum limit for integers.");
        }
    }
    catch (const overflow_error &e)
    {
        // e.what() retrieves the string passed to the constructor above
        cout << "Caught: " << e.what() << endl;
    }

    return 0;
}