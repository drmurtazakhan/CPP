// compile: g++ custom_exception_InsufficientFunds.cpp -o custom_exception_InsufficientFunds.exe
// run: ./custom_exception_InsufficientFunds.exe

// This program demonstrates how to create and use a custom exception class in C++
// alongside a BankAccount class to safely manage account transactions.

#include <iostream>
#include <string>

using namespace std;

// 1. Custom Exception Class
class InsufficientFunds
{
public:
    InsufficientFunds(double amount, double currentBalance)
    {
        message = "Transaction Failed: Attempted to withdraw $" + to_string(amount) +
                  ", but current balance is only $" + to_string(currentBalance) + ".";
    }

    string what() const
    {
        return message;
    }

private:
    string message;
};

// 2. Business Logic Class
class BankAccount
{
public:
    BankAccount(double initialBalance)
    {
        if (initialBalance >= 0)
        {
            balance = initialBalance;
        }
        else
        {
            balance = 0.0;
        }
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Successfully deposited $" << amount << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            throw InsufficientFunds(amount, balance);
        }
        balance -= amount;
        cout << "Successfully withdrew $" << amount << endl;
    }

    void checkBalance() const
    {
        cout << "Current Balance: $" << balance << endl;
    }

private:
    double balance;
};

int main()
{
    // Create a BankAccount object with an initial balance of $50.00
    BankAccount myAccount(50.00);

    // try block to handle potential exceptions
    try
    {
        myAccount.checkBalance();

        cout << "\n--- Depositing Money ---" << endl;
        myAccount.deposit(25.00);
        myAccount.checkBalance();

        cout << "\n--- Successful Withdrawal ---" << endl;
        myAccount.withdraw(30.00); // Balance becomes $45.00
        myAccount.checkBalance();

        cout << "\n--- Failed Withdrawal (Throws Exception) ---" << endl;
        myAccount.withdraw(100.00); // Throws exception! Jumps directly to catch block

        // NOTE: Any code placed here would be skipped!
        cout << "This line will never be reached." << endl;
    }
    catch (const InsufficientFunds &e)
    {
        cout << e.what() << endl;
    }

    myAccount.checkBalance();
    return 0;
}