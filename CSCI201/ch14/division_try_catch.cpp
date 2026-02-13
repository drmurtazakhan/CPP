//division_try_catch.cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    double dividend, divisor, quotient;

    cout << "Enter the dividend: ";
    cin >> dividend;
    cout << "Enter the divisor: ";
    cin >> divisor;

    try {
        // Step 1: Detect the undesirable situation
        if (divisor == 0) {
            // Step 2: Throw an exception (we are throwing a string object)
            throw string("Division by zero error!");
        }

        // This line only executes if no exception is thrown
        quotient = dividend / divisor;
        cout << "The quotient is: " << quotient << endl;
    }
    catch (string message) {
        // Step 3: Catch the exception and handle it
        cout << "Exception: " << message << endl;
    }

    cout << "The program has finished its task." << endl;

    return 0;
}