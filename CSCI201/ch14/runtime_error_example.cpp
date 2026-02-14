// runtime_error_example.cpp
#include <iostream>
#include <stdexcept> // Required for runtime_error and overflow_error

using namespace std;

int main() {
    try {
        // In a real scenario, this would be a calculation that 
        // exceeds the limit of the data type.
        bool errorCondition = true;

        if (errorCondition) {
            throw overflow_error("The value is too large to be stored!");
        }
    }
    catch (const overflow_error& e) {
        // Using the what() function as mentioned in your slide
        cout << "Runtime Error Caught: " << e.what() << endl;
    }

    return 0;
}