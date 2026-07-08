// File Name: enum_courses.cpp
// Compile: g++ enum_courses.cpp -o enum_courses.exe
// Run: ./enum_courses.exe
// This program demonstrates the use of enum with a switch statement.

#include <iostream>
using namespace std;

// Define an enumeration type called courses.
// Each course name is an enumerator.
//
// ALGEBRA     = 0
// BASIC       = 1
// PASCAL      = 2
// CPP         = 3
// PHILOSOPHY  = 4
// ANALYSIS    = 5
// CHEMISTRY   = 6
// HISTORY     = 7

enum courses
{
    ALGEBRA,
    BASIC,
    PASCAL,
    CPP,
    PHILOSOPHY,
    ANALYSIS,
    CHEMISTRY,
    HISTORY
};

int main()
{
    // Declare a variable of type courses.
    courses registered;

    char ch1, ch2;

    cout << "Enter first two letters of a course: ";
    cin >> ch1 >> ch2;

    // Use switch statement to determine the course.
    switch (ch1)
    {
    // If first letter is A or a
    case 'a':
    case 'A':

        // Check second letter
        if (ch2 == 'l' || ch2 == 'L')
            registered = ALGEBRA;
        else
            registered = ANALYSIS;

        break;

    // If first letter is B or b
    case 'b':
    case 'B':

        registered = BASIC;
        break;

    // If first letter is C or c
    case 'c':
    case 'C':

        // CH = Chemistry
        // CP = C++ Programming
        if (ch2 == 'h' || ch2 == 'H')
            registered = CHEMISTRY;
        else
            registered = CPP;

        break;

    // If first letter is H or h
    case 'h':
    case 'H':

        registered = HISTORY;
        break;

    // If first letter is P or p
    case 'p':
    case 'P':

        // PA = Pascal
        // PH = Philosophy
        if (ch2 == 'a' || ch2 == 'A')
            registered = PASCAL;
        else
            registered = PHILOSOPHY;

        break;

    // Any other input is invalid
    default:

        cout << "Illegal input." << endl;
        return 1;
    }

    // Display the selected course.
    cout << "Registered course value is: "
         << registered << endl;

    return 0;
}