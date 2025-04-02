#include <iostream>
using namespace std;

// Base class: Employee
class Employee {
protected:
    string name;
    int id;
public:
    Employee(string empName, int empId) : name(empName), id(empId) {}
    
    void displayInfo() {
        cout << "Employee ID: " << id << ", Name: " << name << endl;
    }
};

// Derived class: SalaryEmployee
class SalaryEmployee : public Employee {
private:
    double monthlySalary;
public:
    SalaryEmployee(string empName, int empId, double salary) 
        : Employee(empName, empId), monthlySalary(salary) {}
    
    void displaySalary() {
        cout << "Monthly Salary: $" << monthlySalary << endl;
    }
};

// Derived class: CommissionEmployee
class CommissionEmployee : public Employee {
private:
    double salesAmount;
    double commissionRate;
public:
    CommissionEmployee(string empName, int empId, double sales, double rate) 
        : Employee(empName, empId), salesAmount(sales), commissionRate(rate) {}
    
    void displayCommission() {
        double commission = salesAmount * commissionRate;
        cout << "Commission Earned: $" << commission << endl;
    }
};

int main() {
    // Creating a SalaryEmployee object
    SalaryEmployee salariedEmp("John Doe", 101, 5000.00);
    salariedEmp.displayInfo();
    salariedEmp.displaySalary();
    
    cout << endl;
    
    // Creating a CommissionEmployee object
    CommissionEmployee commissionEmp("Jane Smith", 102, 20000.00, 0.10);
    commissionEmp.displayInfo();
    commissionEmp.displayCommission();
    
    return 0;
}