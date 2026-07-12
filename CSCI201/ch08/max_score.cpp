// File name: max_score.cpp
// compile: g++ max_score.cpp -o max_score.exe
// run: ./max_score.exe

#include <iostream>

using namespace std;

int main()
{
    // Define the number of students and tests
    const int STUDENTS = 5;
    const int TESTS = 3;

    // Initialize the 2D array with student scores
    double scores[STUDENTS][TESTS] = {
        {75, 50, 90},
        {65, 90, 85},
        {80, 80, 80},
        {95, 70, 60},
        {50, 60, 70}};

    double largest;
    int row, col;

    // Iterate through each student (row)
    for (row = 0; row < STUDENTS; row++)
    {
        // Assume the first test score is the largest to start
        largest = scores[row][0];

        // Iterate through the remaining test scores (columns)
        for (col = 1; col < TESTS; col++)
        {
            // If the current score is higher, update largest
            if (scores[row][col] > largest)
            {
                largest = scores[row][col];
            }
        }

        // Display the largest score found for this student
        cout << "The largest score for student " << row + 1
             << " = " << largest << endl;
    }

    return 0;
}