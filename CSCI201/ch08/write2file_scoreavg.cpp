// compile: g++ write2file_scoreavg.cpp -o write2file_scoreavg.exe
// run: ./write2file_scoreavg.exe
/*
 * Purpose:
 *   - Store the scores of 5 students (3 tests each) in a 2D array.
 *   - Compute the average score of each student.
 *   - Write the scores and average to the file "scores_avg.txt".
 */

#include <iostream>
#include <fstream>
#include <iomanip> // For setprecision()

using namespace std;

int main()
{
    // Number of students and tests
    const int STUDENTS = 5;
    const int TESTS = 3;

    // Initialize the 2D array with students' test scores
    double scores[STUDENTS][TESTS] =
        {
            {75, 50, 90},
            {65, 90, 85},
            {80, 80, 80},
            {95, 70, 60},
            {50, 60, 70}};

    // Open the output file
    ofstream outFile("scores_avg.txt");

    // Check if the file opened successfully
    if (!outFile)
    {
        cout << "Error opening output file!" << endl;
        return 1;
    }

    // Display average with 2 decimal places
    outFile << fixed << setprecision(2);

    // Process each student's scores
    for (int i = 0; i < STUDENTS; i++)
    {
        double sum = 0;

        for (int j = 0; j < TESTS; j++)
        {
            outFile << scores[i][j] << " ";
            sum += scores[i][j];
        }

        // Compute the average
        double average = sum / TESTS;

        // Write the average to file
        outFile << average << endl;
    }

    // Close the file
    outFile.close();

    cout << "Scores and averages have been written to scores_avg.txt" << endl;

    return 0;
}