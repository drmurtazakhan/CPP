// compile: g++ parallel_arrays.cpp -o parallel_arrays.exe
// run: ./parallel_arrays.exe
/*
 * Purpose:
 *   - Demonstrate parallel arrays.
 *   - Store student IDs and their course grades.
 *   - Display the contents using a loop.
 */

#include <iostream>

using namespace std;

int main()
{
    // Number of students
    const int SIZE = 5;

    // Parallel arrays
    // studentId[i] and courseGrade[i] belong to the same student.
    int studentId[SIZE] = {23456, 86723, 22356, 92733, 11892};
    char courseGrade[SIZE] = {'A', 'B', 'C', 'B', 'D'};

    // Display a heading
    cout << "Student ID\tCourse Grade" << endl;
    cout << "----------------------------" << endl;

    // Display the contents of both arrays
    for (int i = 0; i < SIZE; i++)
    {
        cout << studentId[i] << "\t\t"
             << courseGrade[i] << endl;
    }

    return 0;
}