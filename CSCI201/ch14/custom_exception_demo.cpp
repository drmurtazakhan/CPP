// custom_exception_demo.cpp
#include <iostream>
#include <string>

using namespace std;

// 1. Define your own exception class
class InsufficientFunds {
public:
    // Constructor to store specific details about the error
    InsufficientFunds(double amount) {
        message = "Transaction Failed: You tried to withdraw $" + to_string(amount) + 
                  " but your balance is too low.";
    }

    // The function what() returns the error message
    string what() const {
        return message;
    }

private:
    string message; // Member variable to hold error details
};

int main() {
    double balance = 50.00;
    double withdrawal;

    cout << "Current Balance: $" << balance << endl;
    cout << "Enter withdrawal amount: ";
    cin >> withdrawal;

    try {
        if (withdrawal > balance) {
            // 2. Use the throw statement to "signal" the custom exception
            throw InsufficientFunds(withdrawal);
        }
        balance -= withdrawal;
        cout << "Success! New balance: $" << balance << endl;
    }
    // 3. Catch your specific custom class
    catch (const InsufficientFunds& e) {
        cout << e.what() << endl;
    }

    return 0;
}