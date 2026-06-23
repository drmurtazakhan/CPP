// If_Else_v1.cpp
// compile: g++ If_Else_v1.cpp -o If_Else_v1.exe
// run:     ./If_Else_v1.exe
/*
    Program: Interest Rate Determination
    Purpose: Demonstrate the use of nested if...else statements.

    Interest Rate Rules:
    - Balance > 50,000      --> 7%
    - Balance >= 25,000     --> 5%
    - Balance >= 1,000      --> 3%
    - Otherwise             --> 0%
*/

#include <iostream>
#include <iomanip>      // For fixed and setprecision

using namespace std;

int main()
{
    double balance;        // Customer's account balance
    double interestRate;   // Interest rate based on balance

    // Get balance from the user
    cout << "Enter account balance: $";
    cin >> balance;

    // Determine the interest rate using nested if...else statements
    if (balance > 50000.00)
    {
        // Balance is greater than $50,000
        interestRate = 0.07;
    }
    else
    {
        if (balance >= 25000.00)
        {
            // Balance is between $25,000 and $50,000
            interestRate = 0.05;
        }
        else
        {
            if (balance >= 1000.00)
            {
                // Balance is between $1,000 and $24,999.99
                interestRate = 0.03;
            }
            else
            {
                // Balance is less than $1,000
                interestRate = 0.00;
            }
        }
    }

    // Display the interest rate
    cout << fixed << setprecision(2);

    cout << "\nAccount Balance : $" << balance << endl;
    cout << "Interest Rate   : " << (interestRate * 100) << "%" << endl;

    // Calculate and display interest earned
    double interestEarned = balance * interestRate;

    cout << "Interest Earned : $" << interestEarned << endl;

    return 0;
}