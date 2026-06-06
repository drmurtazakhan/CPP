// testStudentWay1.cpp
// compile: g++ testStudentWay1.cpp -o testStudentWay1.exe
// run: ./testStudentWay1.exe
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    // Way 1: A traditional default constructor with NO parameters
    Student()
    {
        name = "Unknown";
        gpa = 0.0;
    }

    // Overloaded parameterized constructor
    Student(string studentName, double studentGpa)
    {
        name = studentName;
        gpa = studentGpa;
    }

    void print() const
    {
        cout << name << " (GPA: " << gpa << ")" << endl;
    }

private:
    string name;
    double gpa;
};

int main()
{
    // Triggers Way 1: No arguments provided
    Student studentA;

    // Triggers the parameterized constructor
    Student studentB("Alice", 3.8);

    cout << "--- Way 1 Results ---" << endl;
    studentA.print(); // Prints: Unknown (GPA: 0)
    studentB.print(); // Prints: Alice (GPA: 3.8)

    return 0;
}