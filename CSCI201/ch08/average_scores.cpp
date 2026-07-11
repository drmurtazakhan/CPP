// File name: average_scores.cpp
// compile: g++ average_scores.cpp -o average_scores.exe
// run: ./average_scores.exe

// Program to find the average test score and output the average
// test score and all the test scores that are less than
// the average test score.
#include <iostream>
#include <iomanip> // Required for output formatting

using namespace std;

int main()
{
    // Declare integer variables for the five individual test scores
    int test0, test1, test2, test3, test4;

    // Declare a double to store the calculated average
    double average;

    // Set output to fixed-point notation and display 2 decimal places
    cout << fixed << showpoint << setprecision(2);

    // Prompt the user for input
    cout << "Enter five test scores: ";
    cin >> test0 >> test1 >> test2 >> test3 >> test4;
    cout << endl;

    // Calculate the average by summing scores and dividing by 5.0
    // Using 5.0 ensures floating-point division
    average = (test0 + test1 + test2 + test3 + test4) / 5.0;

    // Output the calculated average
    cout << "The average test score = " << average << endl;

    return 0;
}