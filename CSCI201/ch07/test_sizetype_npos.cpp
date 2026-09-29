// compile: g++ test_sizetype_npos.cpp -o test_sizetype_npos.exe
// run: ./test_sizetype_npos.exe

#include <iostream>
#include <string>

// Bring the standard namespace into scope to omit std:: prefixes
using namespace std;

int main()
{
    // Initialize a target string for searching
    string text = "Hello, welcome to C++ programming!";

    // ---------------------------------------------------------
    // 1. Successful Search Example ("welcome")
    // ---------------------------------------------------------
    // string::size_type is an unsigned integer type guaranteed to hold
    // any valid string index or the special constant string::npos.
    string::size_type pos1 = text.find("welcome");

    // string::npos is returned by find() when a substring is NOT present.
    // Check if the substring was found by comparing pos1 against string::npos.
    if (pos1 == string::npos)
    {
        cout << "'welcome' was not found in the string.\n";
    }
    else
    {
        // Output the 0-based index where the match begins
        cout << "'welcome' was found at index position: " << pos1 << "\n";
    }

    // ---------------------------------------------------------
    // 2. Unsuccessful Search Example ("Java")
    // ---------------------------------------------------------
    // Perform a search for a substring that does not exist in 'text'
    string::size_type pos2 = text.find("Java");

    // Since "Java" is missing, text.find() evaluates to string::npos
    if (pos2 == string::npos)
    {
        cout << "'Java' was not found (returned string::npos).\n";
    }
    else
    {
        cout << "'Java' was found at index position: " << pos2 << "\n";
    }

    return 0;
}