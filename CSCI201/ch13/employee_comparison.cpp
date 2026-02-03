// File name: employee_comparison.cpp
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;

public:
    Employee(string n = "", double s = 0) : name(n), salary(s) {}

    // 1. Using 'this' to access instance variables
    // No need to pass the object; 'this' points to the one that called the method.
    void setSalary(double salary) {
        // 'this->salary' is the instance variable
        // 'salary' is the local parameter
        this->salary = salary; 
    }

    // 2. Passing an object as a formal parameter
    // To compare, we are 'inside' one object and 'looking' at another.
    bool hasHigherSalaryThan(Employee otherEmp) {
        // this->salary: Salary of the object that called the method
        // otherEmp.salary: Salary of the object passed in the parentheses
        if (this->salary > otherEmp.salary) {
            return true;
        }
        return false;
    }

    void print() {
        cout << name << " ($" << salary << ")";
    }
};

int main() {
    Employee emp1("Alice", 50000);
    Employee emp2("Bob", 60000);

    // Concept 1: The 'this' keyword
    // When we call setSalary, 'this' becomes the address of emp1
    emp1.setSalary(55000);

    // Concept 2: Passing an object
    // emp1 is the "caller" (this), emp2 is the "parameter" (otherEmp)
    if (emp1.hasHigherSalaryThan(emp2)) {
        cout << "Alice makes more than Bob." << endl;
    } else {
        cout << "Alice does not make more than Bob." << endl;
    }

    return 0;
}