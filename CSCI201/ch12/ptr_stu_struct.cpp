#include <iostream>
#include <cstring> // Needed for strcpy
using namespace std;

// Define the structure based on your image
struct studentType {
    char name[26];
    double gpa;
    int sID;
    char grade;
};

// Function to print the student details using a pointer
void printStudent(studentType* ptr) {
    cout << "--- Student Record ---" << endl;
    // Using the arrow operator (->) to access member variables
    cout << "Name:  " << ptr->name << endl;
    cout << "GPA:   " << ptr->gpa << endl;
    cout << "ID:    " << ptr->sID << endl;
    cout << "Grade: " << ptr->grade << endl;
}

int main() {
    // 1. Create a student object
    studentType student;

    // 2. Create a pointer and point it to the student
    studentType* studentPtr = &student;

    // 3. Assign values using the arrow operator (as shown in your image)
    strcpy(studentPtr->name, "John Smith"); // Copying text into the char array
    studentPtr->gpa = 3.9;
    studentPtr->sID = 12345;
    studentPtr->grade = 'A';

    // 4. Call the print function
    printStudent(studentPtr);

    return 0;
}