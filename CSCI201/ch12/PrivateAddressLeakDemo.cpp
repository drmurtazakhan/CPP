#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance; // This should be protected!

public:
    BankAccount(int b) : balance(b) {}

    // DANGEROUS: Returning the address of a private member
    int* getBalanceAddress() {
        return &balance; 
    }

    void showBalance() {
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount myAccount(1000);
    myAccount.showBalance();

    // 1. The "Leak": We get the address of the private variable
    int* hackerPointer = myAccount.getBalanceAddress();

    // 2. The "Attack": We use the address to change private data from outside
    *hackerPointer = 999999; 

    cout << "\n--- After unauthorized access ---" << endl;
    myAccount.showBalance(); // The balance changed without using a class function!

    return 0;
}