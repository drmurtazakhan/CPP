// File name: employee_operator_overload.cpp
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;

public:
    Employee(string n = "", double s = 0) : name(n), salary(s) {}

    // Overloading the > operator as a member function
    // We pass the 'other' employee by const reference for efficiency
    bool operator>(const Employee& otherEmp) const {
        // 'salary' is implicitly this->salary (the left-hand side object)
        // 'otherEmp.salary' is the right-hand side object
        if (this->salary > otherEmp.salary) {
            return true;
        }
        return false;
    }

    void print() const {
        cout << name << " ($" << salary << ")";
    }
};

int main() {
    Employee emp1("Alice", 75000);
    Employee emp2("Bob", 60000);

    cout << "Comparing salaries:" << endl;
    emp1.print(); cout << " vs "; emp2.print(); cout << endl;

    // Now we can use the math symbol > directly!
    if (emp1 > emp2) {
        cout << "Result: The first employee has a higher salary." << endl;
    } else {
        cout << "Result: The first employee does not have a higher salary." << endl;
    }

    return 0;
}