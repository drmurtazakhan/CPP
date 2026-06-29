// testPostfixSTL.cpp
/*
   HOW TO COMPILE AND RUN:
   1. Compile: g++ testPostfixSTL.cpp -o testPostfixSTL.exe
   2. Run:     .\testPostfixSTL.exe
*/

#include <iostream>
#include <stack> // Include C++ STL stack
#include <string>
#include <sstream> // Used to tokenize the string by spaces

using namespace std;

int main()
{
    // Hardcoded postfix expression ending with the '=' operator
    // Equivalent to: (6 + 3) * 2 = 18
    string expression = "6 3 + 2 * =";

    // STL stack to hold operands (numbers)
    stack<double> myStack;

    cout << "Evaluating Postfix Expression: " << expression << endl;
    cout << "------------------------------------------------" << endl;

    stringstream ss(expression);
    string token;

    // Scan tokens from left to right
    while (ss >> token)
    {
        // Case 1: If the token is the '=' operator, the calculation is complete
        if (token == "=")
        {
            cout << "Parsed '=' : Finalizing evaluation." << endl;
            break; // Exit the loop to print the final result
        }

        // Case 2: If the token is a math operator, perform the calculation
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            // Pop the top two elements
            // Remember: LIFO order means the first pop is operand 2
            double op2 = myStack.top();
            myStack.pop();

            double op1 = myStack.top();
            myStack.pop();

            double result = 0;

            if (token == "+")
            {
                result = op1 + op2;
                cout << "Parsed '+' : " << op1 << " + " << op2 << " = " << result << endl;
            }
            else if (token == "-")
            {
                result = op1 - op2;
                cout << "Parsed '-' : " << op1 << " - " << op2 << " = " << result << endl;
            }
            else if (token == "*")
            {
                result = op1 * op2;
                cout << "Parsed '*' : " << op1 << " * " << op2 << " = " << result << endl;
            }
            else if (token == "/")
            {
                if (op2 != 0)
                {
                    result = op1 / op2;
                    cout << "Parsed '/' : " << op1 << " / " << op2 << " = " << result << endl;
                }
                else
                {
                    cout << "Error: Division by zero!" << endl;
                    return 1;
                }
            }

            // Push the calculated result back onto the stack
            myStack.push(result);
        }

        // Case 3: If the token is a number, push it onto the stack
        else
        {
            double num = stod(token);
            myStack.push(num);
            cout << "Parsed Number: Pushed " << num << " onto stack." << endl;
        }
    }

    // Print final verification phase
    cout << "------------------------------------------------" << endl;

    // A correct expression will leave exactly ONE number on the stack
    if (myStack.size() == 1)
    {
        cout << "Final Result: " << myStack.top() << endl;
        myStack.pop(); // Clear the final item
    }
    else
    {
        cout << "Error: Invalid postfix expression structure (too many or too few operands)." << endl;
    }

    return 0;
}