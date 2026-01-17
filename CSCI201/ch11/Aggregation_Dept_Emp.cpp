#include <iostream>
#include <string>
using namespace std;

class Department {
    string deptName;
    string location;
public:
    Department(string name, string loc) : deptName(name), location(loc) {}
    
    string getName() { return deptName; }
    string getLocation() { return location; }
};

class Employee {
    string name;
    // AGGREGATION: Pointer to a shared Department object
    Department* dept; 

public:
    // Constructor: Employee starts with a department
    Employee(string n, Department* d) : name(n), dept(d) {}

    // FLEXIBILITY: Ability to change departments (impossible with references)
    void setDept(Department* newDept) {
        dept = newDept;
    }

    void display() {
        cout << "Employee: " << name << " | ";
        if (dept) {
            cout << "Dept: " << dept->getName() 
                 << " (" << dept->getLocation() << ")" << endl;
        } else {
            cout << "Unassigned" << endl;
        }
    }
};

int main() {
    // 1. Create Departments (Only 2 objects in memory)
    Department sales("Sales", "Floor 1");
    Department tech("Technology", "Floor 5");

    // 2. Create Employees pointing to those departments
    Employee emp1("Alice", &sales);
    Employee emp2("Bob", &tech);
    Employee emp3("Charlie", &tech); // Shared: Bob and Charlie point to the same object

    cout << "--- Initial Assignment ---" << endl;
    emp1.display();
    emp2.display();
    emp3.display();

    // 3. Changing Department (Transferring Bob to Sales)
    cout << "\n--- After Bob's Transfer ---" << endl;
    emp2.setDept(&sales);
    emp2.display();

    return 0;
}