#include <iostream>
using namespace std;

int main()
{
    // Define constants for the values of dimes, nickels, and pennies
    const unsigned int CENTS_IN_A_DIME = 10;
    const unsigned int CENTS_IN_A_NICKEL = 5;

    // Declare variables to store dimes, nickels, and pennies
    unsigned int dimes, nickels, pennies, remainingCents;

    // Input: Total cents to convert
    unsigned int totalCents = 87;

    dimes = totalCents / CENTS_IN_A_DIME;          // Calculate dimes
    remainingCents = totalCents % CENTS_IN_A_DIME; // Remaining cents after dimes

    nickels = remainingCents / CENTS_IN_A_NICKEL;  // Calculate nickels
    pennies = remainingCents % CENTS_IN_A_NICKEL;  // Remaining cents after nickels

    // Output the results
    cout << "Total Cents: " << totalCents << endl;
    cout << "Dimes: " << dimes << endl;
    cout << "Nickels: " << nickels << endl;
    cout << "Pennies: " << pennies << endl;

    return 0;
}
