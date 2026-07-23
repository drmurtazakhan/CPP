// compile: g++ student_scores_manager.cpp -o student_scores_manager.exe
// run: ./student_scores_manager.exe

// This program demonstrates how to use an array of structs to store student records with multiple test scores and calculate their grades
#include <iostream>
#include <string>

using namespace std;

// Global constant for the number of test scores
const int NUM_SCORES = 3;

// Modified struct containing an array of scores
struct StudentType
{
    int id;
    string name;
    double scores[NUM_SCORES]; // Array inside the struct to hold test1, test2, test3
    char grade;                // Left uninitialized initially
};

// Function prototypes
void calculateGrades(StudentType students[], int size);
void printStudents(const StudentType students[], int size);

int main()
{
    const int SIZE = 3;

    // Declare and initialize the array of structs with ID, Name, and 3 Scores
    // The grade field is omitted here so the calculation function can assign it later
    StudentType studentList[SIZE] = {
        {23456, "Alice Smith", {95.5, 92.0, 88.5}},  // Average ~92.0 (A)
        {86723, "Bob Jones", {82.0, 79.5, 84.5}},    // Average ~82.0 (B)
        {22356, "Charlie Brown", {71.0, 68.0, 75.0}} // Average ~71.3 (C)
    };

    // 1. Process the records to compute averages and assign grades
    calculateGrades(studentList, SIZE);

    // 2. Display the complete records
    printStudents(studentList, SIZE);

    return 0;
}

// Function to calculate the average score and assign the appropriate grade
void calculateGrades(StudentType students[], int size)
{
    for (int i = 0; i < size; i++)
    {
        double sum = 0.0;

        // Loop through the inner scores array for the current student
        for (int j = 0; j < NUM_SCORES; j++)
        {
            sum += students[i].scores[j];
        }

        double average = sum / NUM_SCORES;

        // Assign grade based on the computed average
        if (average >= 90.0)
        {
            students[i].grade = 'A';
        }
        else if (average >= 80.0)
        {
            students[i].grade = 'B';
        }
        else if (average >= 70.0)
        {
            students[i].grade = 'C';
        }
        else if (average >= 60.0)
        {
            students[i].grade = 'D';
        }
        else
        {
            students[i].grade = 'F';
        }
    }
}

// Function to print the comprehensive data report
void printStudents(const StudentType students[], int size)
{
    cout << "ID\t\tName\t\t\tTest Scores\t\tGrade" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int i = 0; i < size; i++)
    {
        // Print basic details
        cout << students[i].id << "\t\t"
             << students[i].name << "\t\t";

        // Print the contents of the nested scores array
        cout << "[";
        for (int j = 0; j < NUM_SCORES; j++)
        {
            cout << students[i].scores[j];
            if (j < NUM_SCORES - 1)
            {
                cout << ", ";
            }
        }
        cout << "]\t\t";

        // Print the calculated grade
        cout << students[i].grade << endl;
    }
}