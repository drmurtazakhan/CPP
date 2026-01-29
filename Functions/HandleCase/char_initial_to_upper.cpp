#include <iostream>
#include <cctype>  // For the toupper function
using namespace std;

// Function prototype
char getInitial();

int main() {
    // Call the function and store the returned initial
    char initial = getInitial();
    
    // Display the returned initial
    cout << "Your initial is: " << initial << endl;

    return 0;
}

// Function definition
char getInitial() {
    char initial;
    
    cout << "Please enter your first initial followed by a period (e.g., 'A.'): ";
    cin >> initial;  // Read the initial
    
    char period;  
    cin >> period;  // Read the period

    // Ensure that the second character is a period
    if (period == '.') {
        // Convert the initial to uppercase
        return toupper(initial);  // Return the uppercase initial
    } else {
        cout << "Invalid input. Please enter an initial followed by a period." << endl;
        return '\0';  // Return null character in case of invalid input
    }
}
