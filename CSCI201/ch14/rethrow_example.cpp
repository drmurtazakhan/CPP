// compile: g++ rethrow_example.cpp -o rethrow_example.exe
// run: ./rethrow_example.exe

#include <iostream>
#include <string>

using namespace std;

// This function "partially" handles the error
void processPayment(double amount)
{
    try
    {
        if (amount <= 0)
        {
            throw string("Invalid Amount");
        }
        cout << "Processing payment of $" << amount << "..." << endl;
    }
    catch (string e)
    {
        // 1. Partial processing: Log the error to the console
        cout << "[LOG]: Payment system detected an error: " << e << endl;

        // 2. Rethrow the same exception to the calling function (main)
        throw;
    }
}

int main()
{
    string userName = "Alice"; // Local variable accessible in main's try and catch blocks
    double userAmount;

    try
    {
        // Correct usage: process a valid payment
        userAmount = 10.0;
        processPayment(userAmount);

        // Call the function that will throw/rethrow
        userAmount = -5.0;
        processPayment(userAmount);
    }
    catch (string e)
    {
        // 3. Final handling: Personalize message using userName
        cout << userName << ", we could not process your payment: " << e << endl;
    }

    return 0;
}