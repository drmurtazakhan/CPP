// Student_NoConstructor.cpp
// compile: g++ Student_NoConstructor.cpp -o Student_NoConstructor.exe
// run: ./Student_NoConstructor.exe
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
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

    Student blankStudent;
    blankStudent.print();

    return 0;
}