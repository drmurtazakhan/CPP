// StudentWithStaticMember.cpp
// compile: g++ StudentWithStaticMember.cpp -o StudentWithStaticMember.exe
// run: ./StudentWithStaticMember.exe
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    // 1. Keyword 'static' used to declare a shared class variable
    // This tracks the total number of students created
    static int totalStudents;

    // Non-static member variables (Each student gets their own unique copy)
    string name;
    double gpa;

    // Constructor
    Student(string studentName, double studentGpa)
    {
        name = studentName;
        gpa = studentGpa;

        // 5. All objects share 'totalStudents'.
        // Incrementing it here updates it for the entire class.
        totalStudents++;
    }

    // 1. Keyword 'static' used to declare a class function
    static void printTotalCount()
    {
        // Note: A static function can ONLY access static variables
        cout << "Current Total Students in Database: " << totalStudents << endl;
    }
};

// CRITICAL STEP IN C++: Static member variables must be defined and
// initialized outside the class block before main() runs.
int Student::totalStudents = 0;

int main()
{
    cout << "--- 3. Existence Without Objects ---" << endl;
    // 3. Static variables exist even if NO objects have been created yet.
    // 2. We access the public static function using the Class Name and Scope Resolution Operator (::)
    Student::printTotalCount(); // Prints: 0

    cout << "\n--- Creating Objects ---" << endl;
    // Let's create two individual student objects
    Student s1("Alice", 3.9);
    Student s2("Bob", 3.5);

    cout << "\n--- 4. Unique Non-Static Copies ---" << endl;
    // 4. Multiple objects each have their own independent copy of non-static variables
    cout << "s1's name: " << s1.name << " | GPA: " << s1.gpa << endl;
    cout << "s2's name: " << s2.name << " | GPA: " << s2.gpa << endl;

    cout << "\n--- 5. Shared Static Member ---" << endl;
    // 5. Both objects share the exact same 'totalStudents' variable.
    // Changing it through the class or seeing it through an object reflects the same number.
    cout << "Total counted via Class Name (::): " << Student::totalStudents << endl;

    return 0;
}