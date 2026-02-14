// runtime_error_example2.cpp
#include <iostream>
#include <stdexcept> // Required for runtime_error and overflow_error
#include <limits>    // Required to check numeric limits

using namespace std;

int main() {
    // Hard-coded values that will cause an overflow
    // INT_MAX is usually 2,147,483,647
    int current_value = 2147483640; 
    int added_value = 100; // This will push the sum beyond the maximum value for an int
    //int added_value = 1; // Ths will not cause an overflow

    cout << "Starting Value: " << current_value << endl;
    cout << "Attempting to add: " << added_value << endl;

    try {
        // Logical check: If we add these, will it exceed the max integer?
        if (current_value > numeric_limits<int>::max() - added_value) {
            // Since the result would be mathematically invalid for an int,
            // we throw a standard overflow_error.
            throw overflow_error("Runtime Error: Integer overflow detected!");
        }

        int sum = current_value + added_value;
        cout << "The sum is: " << sum << endl;
    }
    catch (const overflow_error& e) {
        // e.what() retrieves the string we passed to the constructor above
        cout << "Caught: " << e.what() << endl;
    }

    return 0;
}