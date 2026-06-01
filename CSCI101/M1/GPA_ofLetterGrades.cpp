// GPA_ofLetterGrades.cpp
// compile: g++ GPA_ofLetterGrades.cpp -o GPA_ofLetterGrades.exe
// run:     ./GPA_ofLetterGrades.exe
#include <iostream>

using namespace std;

int main()
{
    // Variable to store the user's input grade
    char grade;

    // Prompt the user for input
    cout << "Enter your letter grade (A, B, C, D, F): ";
    cin >> grade;

    // Convert lowercase input to uppercase to handle both formats smoothly
    grade = toupper(grade);

    // Evaluate the grade using a switch statement
    switch (grade)
    {
    case 'A':
        cout << "The grade point is 4.0." << endl;
        break;
    case 'B':
        cout << "The grade point is 3.0." << endl;
        break;
    case 'C':
        cout << "The grade point is 2.0." << endl;
        break;
    case 'D':
        cout << "The grade point is 1.0." << endl;
        break;
    case 'F':
        cout << "The grade point is 0.0." << endl;
        break;
    // The default case handles any character that is not A, B, C, D, or F
    default:
        cout << "The grade is invalid." << endl;
    }

    return 0;
}