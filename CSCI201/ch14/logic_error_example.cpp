//logic_error_example.cpp
#include <iostream>
#include <string>
#include <stdexcept> // Required for logic_error and out_of_range

using namespace std;

int main() {
    string phrase = "C++ Class";

    try {
        // The string only has indices 0-8. 
        // Accessing index 20 will trigger an out_of_range exception.
        cout << "Character at index 20: " << phrase.at(20) << endl;
    }
    catch (const out_of_range& e) {
        // e.what() returns the standard error message for this class
        cout << "Logic Error Caught: " << e.what() << endl;
    }

    return 0;
}