// File name: average_scores_array.cpp
// compile: g++ average_scores_array.cpp -o average_scores_array.exe
// run: ./average_scores_array.exe

// Program to calculate the average of five test scores
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Declare an array to hold 5 test scores
    int tests[5];
    int sum = 0;
    double average;

    // Set formatting to 2 decimal places
    cout << fixed << showpoint << setprecision(2);

    // Prompt user and store input in the array
    cout << "Enter 5 test scores: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> tests[i];
        sum = sum + tests[i]; // Add each score to the total sum
    }

    // Calculate the average
    average = sum / 5.0;

    // Display the results
    cout << "The average test score = " << average << endl;

    return 0;
}