// compile: g++ student_records.cpp -o student_records.exe
// run: ./student_records.exe

// This program demonstrates how to use an array of structs to store student records
#include <iostream>
#include <string>

using namespace std;

// Define the struct grouping a single student's data together
struct StudentType
{
    int id;
    string name;
    char grade;
};

// Helper function prototype to display the student records
void printStudents(const StudentType students[], int size);

int main()
{
    // The problem requires an array of struct type initialized with 3 records
    const int SIZE = 3;

    // Declare and initialize the array of structs
    StudentType studentList[SIZE] = {
        {23456, "Alice Smith", 'A'},
        {86723, "Bob Jones", 'B'},
        {22356, "Charlie Brown", 'C'}};

    // Call the helper function to display the records
    printStudents(studentList, SIZE);

    return 0;
}

// Helper function implementation
// Pass-by-reference (const array) is used here for clean memory management
void printStudents(const StudentType students[], int size)
{
    // Display a clean heading
    cout << "ID\t\tName\t\t\tGrade" << endl;
    cout << "--------------------------------------------" << endl;

    // Loop through the array of structs and print each member using the dot operator
    for (int i = 0; i < size; i++)
    {
        cout << students[i].id << "\t\t"
             << students[i].name << "\t\t"
             << students[i].grade << endl;
    }
}