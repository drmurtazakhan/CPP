// Example2_21.cpp
// compile: g++ Example2_21.cpp -o Example2_21.exe
// run:     ./Example2_21.exe
#include <iostream>
using namespace std;

int main() {
    // 1. Integer Division
    // Because both 29 and 4 are integers, C++ drops the decimal part (fraction). 
    // 29 divided by 4 is 7.25, so it outputs exactly 7.
    cout << 29 / 4 << endl;

    // 2. String Literal
    // Text enclosed in double quotes " " is printed exactly as it appears.
    cout << "Hello there." << endl;

    // 3. Integer Literal
    // Prints the literal number 12.
    cout << 12 << endl;

    // 4. String Literal containing Math symbols
    // Because 4 + 7 is inside double quotes, C++ treats it as plain text, not math.
    cout << "4 + 7" << endl;

    // 5. Arithmetic Expression
    // No quotes here! C++ evaluates the mathematical expression first, then prints the result.
    cout << 4 + 7 << endl;

    // 6. Character Literal
    // Text inside single quotes ' ' represents a single character data type (char).
    cout << 'A' << endl;

    // 7. Combining (Chaining) Text and Math
    // First, it prints the literal text "4 + 7 = ". 
    // Then, it evaluates the math 4 + 7 and prints the resulting 11.
    cout << "4 + 7 = " << 4 + 7 << endl;

    // 8. Operator Precedence (Order of Operations)
    // C++ follows standard math rules (PEMDAS). Multiplication happens before addition.
    // 3 * 5 = 15. Then 2 + 15 = 17.
    cout << 2 + 3 * 5 << endl;

    // 9. Escape Sequence (\n)
    // The '\n' character creates a newline break right in the middle of the string.
    // Removed '<< endl' so it matches the book's exact spacing without adding a third blank line.
    cout << "Hello \nthere.";

    return 0;
}