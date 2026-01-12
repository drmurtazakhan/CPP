#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// 1. Define the struct (The Blueprint)
struct studentType {
    string firstName;
    string lastName;
    char courseGrade;
    int testScore;
    int programmingScore;
    double GPA;
};

// 2. Prototype for the print function
// We use 'const' because printing shouldn't modify the data
void printStudentRecord(const studentType &s);

int main() {
    // 3. Declare and initialize
    // Using {} to avoid the "garbage values" you saw earlier!
    studentType newStudent = {}; 

    // Assigning values
    newStudent.firstName = "John";
    newStudent.lastName = "Brown";
    newStudent.GPA = 0.0;
    newStudent.courseGrade = 'A';
    newStudent.testScore = 95;
    newStudent.programmingScore = 98;

    // 4. Call the separate function to print
    printStudentRecord(newStudent);    


    // Demonstrating with another student
    studentType student = {};
    student = newStudent;
    printStudentRecord(student);

    return 0;
}

// 5. Function Definition
void printStudentRecord(const studentType &s) {
    cout << "--- Student Record ---" << endl;
    cout << "Name: " << s.firstName << " " << s.lastName << endl;
    cout << "Course Grade: " << s.courseGrade << endl;
    cout << "Test Score: " << s.testScore << endl;
    cout << "Programming Score: " << s.programmingScore << endl;
    
    cout << fixed << setprecision(2);
    cout << "GPA: " << s.GPA << endl;
    cout << "----------------------" << endl;
}