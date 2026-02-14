// rethrow_example.cpp
#include <iostream>
#include <string>

using namespace std;

// This function "partially" handles the error
void processPayment(double amount) {
    try {
        if (amount <= 0) {
            throw string("Invalid Amount");
        }
        cout << "Processing payment of $" << amount << "..." << endl;
    }
    catch (string e) {
        // 1. Partial processing: Log the error to the console
        cout << "[LOG]: Payment system detected an error: " << e << endl;
        
        // 2. Rethrow the same exception to the calling function (main)
        throw; 
    }
}

int main() {
    double userAmount = -5.0;

    try {
        // Call the function that might throw/rethrow
        processPayment(userAmount);
    }
    catch (string e) {
        // 3. Final handling: Show a user-friendly message
        cout << "USER NOTIFICATION: We could not process your payment: " << e << endl;
    }

    return 0;
}