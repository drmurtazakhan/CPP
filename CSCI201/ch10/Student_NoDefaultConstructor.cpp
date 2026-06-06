// Student_NoDefaultConstructor.cpp
// compile: g++ Student_NoDefaultConstructor.cpp -o Student_NoDefaultConstructor.exe
// run: ./Student_NoDefaultConstructor.exe
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    // Only a Parameterized Constructor is defined
    Student(string studentName, double studentGpa)
    {
        name = studentName;
        gpa = studentGpa;
    }

    void print() const
    {
        cout << name << " has a GPA of " << gpa << endl;
    }

private:
    string name;
    double gpa;
};

int main()
{
    // 1. This works perfectly because it matches the constructor parameters
    Student topStudent("Alice", 3.9);
    topStudent.print();

    // 2. This line will cause a COMPILE ERROR!
    // Student blankStudent;

    return 0;
}