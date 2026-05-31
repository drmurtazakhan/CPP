// Compare_Char_Bool.cpp
// compile: g++ Compare_Char_Bool.cpp -o Compare_Char_Bool.exe 
// run:     ./Compare_Char_Bool.exe

#include <iostream>
using namespace std;

int main() {
    // 1. Defining and comparing char data types
    char letter1 = 'R';
    char letter2 = 'T';

    // This checks if 'R' comes after 'T' in the ASCII table.
    // Since 'R' (82) is smaller than 'T' (84), this statement is false.
    bool charResult = (letter1 > letter2); 

    cout << "Comparing characters:" << endl;
    cout << "Is '" << letter1 << "' > '" << letter2 << "'? " << charResult << endl; 
    cout << "(Prints 0 because the statement is false)" << endl;
    cout << "---------------------------------------" << endl;

    // 2. Defining and comparing bool data types
    // Remember: true is secretly 1, and false is secretly 0.
    bool isSunny = true;   // holds 1
    bool isRaining = false; // holds 0

    // This checks if true (1) is greater than false (0).
    // Since 1 > 0, this statement is true.
    bool boolResult = (isSunny > isRaining); 

    cout << "Comparing boolean values:" << endl;
    cout << "Is isSunny > isRaining? " << boolResult << endl;
    cout << "(Prints 1 because true (1) is greater than false (0))" << endl;

    return 0;
}