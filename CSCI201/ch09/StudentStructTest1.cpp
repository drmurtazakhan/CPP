#include <iostream>
#include <string>
#include <iomanip> // For formatting output

using namespace std;

// 1. Define the studentType struct exactly as shown in the image
struct studentType {
    string firstName;
    string lastName;
    char courseGrade;
    int testScore;
    int programmingScore;
    double GPA;
};

int main() {
    // 2. Declare variables of type studentType
    studentType newStudent;
    studentType student; // Declared but not initialized in the image

    // 3. Assign values to members as shown in the image
    newStudent.GPA = 0.0;
    newStudent.firstName = "John";
    newStudent.lastName = "Brown";

    // 4. Print the record
    cout << "--- Student Record ---" << endl;
    cout << "Name: " << newStudent.firstName << " " << newStudent.lastName << endl;
    cout << "Course Grade: " << newStudent.courseGrade << endl;
    cout << "Test Score: " << newStudent.testScore << endl;
    cout << "Programming Score: " << newStudent.programmingScore << endl;
    
    // Setting precision to 1 decimal place for GPA
    cout << fixed << setprecision(2);
    cout << "GPA: " << newStudent.GPA << endl;

    return 0;
}