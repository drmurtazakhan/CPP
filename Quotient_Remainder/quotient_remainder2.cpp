 #include <iostream> // Include the iostream library for input and output
using namespace std;

int main() {
    cout << "Harper College!" << endl; // Print message to console

    int dividend = 8; 
    int divisor = 3;

    int quotient = dividend / divisor; 
    cout << "The quotient is "  << quotient << endl; // Print the quotient
    
    int remainder = dividend % divisor; 
    cout << "The remainder is "  << remainder << endl; // Print the remainder

    int dividend_check = (divisor * quotient) + remainder;

    cout << "The dividend check is " << dividend_check << endl; // Print the dividend check
    
    return 0; // Indicate successful program termination
    
} 