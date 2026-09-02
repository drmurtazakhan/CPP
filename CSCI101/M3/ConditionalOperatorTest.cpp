// compile: g++ ConditionalOperatorTest.cpp -o ConditionalOperatorTest.exe
// run: ./ConditionalOperatorTest.exe
#include <iostream>
using namespace std;

int main()
{
    // Declare two variables to compare
    int a = 15;
    int b = 20;

    // Syntax: expression1 ? expression2 : expression3
    // If (a >= b) is true, max gets 'a' (expression2).
    // Otherwise, max gets 'b' (expression3).
    int max = (a >= b) ? a : b;

    // Display the inputs and the calculated result
    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
    cout << "Maximum value is: " << max << endl;

    return 0;
}