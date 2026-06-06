// testStudentWay2.cpp
// compile: g++ testStudentWay2.cpp -o testStudentWay2.exe
// run: ./testStudentWay2.exe
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    // Way 2: Single constructor where ALL parameters have default values
    Student(string studentName = "Unknown", double studentGpa = 0.0)
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
    // Triggers Way 2 with ZERO arguments (uses defaults "Unknown" and 0.0)
    Student studentA;

    // Triggers Way 2 with BOTH arguments (overrides the defaults)
    Student studentB("Bob", 3.9);

    cout << "--- Way 2 Results ---" << endl;
    studentA.print(); // Prints: Unknown (GPA: 0)
    studentB.print(); // Prints: Bob (GPA: 3.9)

    return 0;
}