// File name: pass_2d_array.cpp
// compile: g++ pass_2d_array.cpp -o pass_2d_array.exe
// run: ./pass_2d_array.exe

#include <iostream>

using namespace std;

// Function to calculate the average of all scores in a 2D array
// Note: We must specify the number of columns (3) in the parameter declaration
double calculateClassAverage(double arr[][3], int rows)
{
    double totalSum = 0;
    int totalElements = rows * 3; // Total students * total tests

    // Nested loops to traverse the 2D array and sum all scores
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            totalSum += arr[i][j];
        }
    }

    // Return the calculated class average
    return totalSum / totalElements;
}

int main()
{
    const int STUDENTS = 5;
    const int TESTS = 3;

    // Initialize the 2D array with student scores
    double scores[STUDENTS][TESTS] = {
        {75, 50, 90},
        {65, 90, 85},
        {80, 80, 80},
        {95, 70, 60},
        {50, 60, 70}};

    // Call the function and store the result
    double classAverage = calculateClassAverage(scores, STUDENTS);

    // Display the average with an appropriate message
    cout << "The class average for all students is: " << classAverage << endl;

    return 0;
}