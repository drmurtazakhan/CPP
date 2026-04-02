// PostFix2.cpp
/*
   HOW TO COMPILE AND RUN (PowerShell):
   1. Compile: g++ PostFix2.cpp -o PostFix2.exe -mconsole
   2. Run:     .\PostFix2.exe
   
   Note: This program requires an input file named "RpnData.txt" 
   and creates an output file named "RpnOutput.txt".
*/

#include <iostream>  
#include <iomanip>
#include <fstream>
#include "myStack.h" // Uses the array-based stack we discussed

using namespace std; 

// Function Prototypes
void evaluateExpression(ifstream& inpF, ofstream& outF, 
                        stackType<double>& stack,
                        char& ch, bool& isExpOk);
void evaluateOpr(ofstream& out, stackType<double>& stack,
                 char& ch, bool& isExpOk);
void discardExp(ifstream& in, ofstream& out, char& ch);
void printResult(ofstream& outF, stackType<double>& stack,
                 bool isExpOk);

int main()
{
    bool expressionOk;
    char ch;
    stackType<double> stack(100); // Create a stack to hold numbers
    ifstream infile;
    ofstream outfile;
 
    // Open the input file containing postfix expressions
    infile.open("RpnData.txt");

    if (!infile)
    {
        cout << "Error: Could not find RpnData.txt. Program stopping!" << endl;
        return 1;
    }
     
    // Open the output file where results will be saved
    outfile.open("RpnOutput3.txt");

    // Format output to show 2 decimal places
    outfile << fixed << showpoint;
    outfile << setprecision(2); 

    infile >> ch; // Read the first character
    while (infile)
    {
        stack.initializeStack(); // Clear stack for a new expression
        expressionOk = true;     // Reset error flag
        outfile << ch;           // Write the first character to output file

        // Process the expression until an '=' is reached
        evaluateExpression(infile, outfile, stack, ch, expressionOk);
        
        // Print the final answer or an error message
        printResult(outfile, stack, expressionOk);
        
        infile >> ch; // Read the next character for the next loop
    }

    infile.close();
    outfile.close();

    return 0;
}

// This function reads the expression and decides if it's a number or operator
void evaluateExpression(ifstream& inpF, ofstream& outF, 
                        stackType<double>& stack,
                        char& ch, bool& isExpOk)
{
    double num;

    while (ch != '=') // Loop until the end of the math expression
    {
        switch (ch)
        {
        case '#': // '#' is a marker in this program that a number follows
            inpF >> num;
            outF << num;
            if (!stack.isFullStack())
                stack.push(num); // Store the number on the stack
            else
            {
                cout << "Stack Overflow: Expression too long." << endl;
                exit(1); 
            }
            break;
        default: 
            // If it's not a '#', it must be an operator (+, -, *, /)
            evaluateOpr(outF, stack, ch, isExpOk);
        }

        inpF >> ch; // Read the next character
        if (ch != '=')
            outF << " " << ch;
    } 
}



// This function performs the actual math (+, -, *, /)
void evaluateOpr(ofstream& out, stackType<double>& stack,
                 char& ch, bool& isExpOk)
{
    double op1, op2;

    // Check if we have at least two numbers to perform math
    if (stack.isEmptyStack())
    {
        out << " (Error: Not enough operands)";
        isExpOk = false;
    }
    else
    {
        // Get the second number (top of stack)
        op2 = stack.top();
        stack.pop();

        if (stack.isEmptyStack())
        {
            out << " (Error: Not enough operands)";
            isExpOk = false;
        }
        else
        {
            // Get the first number
            op1 = stack.top();
            stack.pop();

            // Perform the operation based on the character read
            switch (ch)
            {
            case '+': 
                stack.push(op1 + op2);
                break;
            case '-': 
                stack.push(op1 - op2);
                break;
            case '*': 
                stack.push(op1 * op2);
                break;
            case '/': 
                if (op2 != 0)
                    stack.push(op1 / op2);
                else
                {
                    out << " (Error: Division by 0)";
                    isExpOk = false;
                }
                break;
            default:  
                out << " (Error: Unknown operator)";
                isExpOk = false;
            }
        } 
    } 
}

// If an error occurs, this function skips the rest of the bad expression
void discardExp(ifstream& in, ofstream& out, char& ch)
{
    while (ch != '=')
    {
        in.get(ch);
        out << ch;
    }
}

// Final step: Checks if the stack has exactly one number (the answer)
void printResult(ofstream& outF, stackType<double>& stack,
                 bool isExpOk)
{
    double result;

    if (isExpOk) 
    {
        if (!stack.isEmptyStack())
        {
            result = stack.top(); // The answer is the only thing left
            stack.pop();

            if (stack.isEmptyStack())
                outF << " = " << result << endl;
            else
                outF << " (Error: Too many numbers/operands)" << endl;
        } 
        else
            outF << " (Error: Empty expression)" << endl;
    } 
    else
    {
        outF << " (Expression ignored due to error)" << endl;
    }
    outF << "_________________________________" << endl;
}