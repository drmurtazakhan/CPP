 #include <iostream> 
using namespace std;

int main() {
    
    int dividend = 11; 
    int divisor = 4;

    int quotient = dividend / divisor; 
    cout << "The quotient is "  << quotient << endl; 

    int remainder = dividend % divisor; 
    cout << "The remainder is "  << remainder << endl; 

    int dividend_check = (divisor * quotient) + remainder;
    cout << "The dividend check is " << dividend_check << endl; 
    
    return 0; 
    
} 

