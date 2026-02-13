//age_exception.cpp
#include <iostream>
#include <string>
#include <limits> // Required to clean the input buffer

using namespace std;

int main() {
    int age;

    cout << "Please enter your age (as a whole number): ";

    try {
        cin >> age;

        // Check if the input failed (e.g., user typed a string like "abc")
        if (cin.fail()) {
            // Clear the error flag so we can use cin again
            cin.clear();
            // Skip the bad input sitting in the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            throw string("Invalid input: You entered text instead of a number.");
        }

        // Check for a logical error (Practical check)
        if (age < 0) {
            throw age; // Throwing the actual integer to show the wrong value
        }

        if (age > 120) {
            // Throwing a generic character array
            throw "That age seems impossible!";
        }

        cout << "Thank you! Your age is registered as: " << age << endl;
    }
    catch (string errorMsg) {
        cout << "Caught a String Exception: " << errorMsg << endl;
    }
    catch (int wrongValue) {
        cout << "Caught an Integer Exception: " << wrongValue << " is not a valid age." << endl;
    }
    catch (...) {
        // This catches "That age seems impossible!" because it's a const char*
        // and any other error we didn't specifically name above.
        cout << "Caught an unknown error or a character array exception!" << endl;
    }

    return 0;
}