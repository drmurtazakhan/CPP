// StructsInArray.cpp
// Compile: g++  StructsInArray.cpp -o StructsInArray.exe
// Run:     ./StructsInArray.exe

// This program demonstrates how to use an array of structs to store employee records
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Define the struct exactly as shown in the image
struct employeeType
{
    string firstName;
    string lastName;
    int personID;
    string deptID;
    double yearlySalary;
    double monthlySalary;
    double yearToDatePaid;
    double monthlyBonus;
};

// Function Prototype: Now accepts the entire array and the active counter
// The array is passed as const so the function cannot accidentally alter employee data
void printEmployeeRecords(const employeeType employees[], int count);

int main()
{
    // Declare an array of 50 components of type employeeType
    employeeType employees[50];

    // Counter variable to keep track of how many records are inserted
    int empCount = 0;

    // 1. Insert Record for the First Employee (Index 0)
    employees[empCount].firstName = "John";
    employees[empCount].lastName = "Doe";
    employees[empCount].personID = 1001;
    employees[empCount].deptID = "IT";
    employees[empCount].yearlySalary = 85000.00;
    employees[empCount].monthlySalary = 7083.33;
    employees[empCount].yearToDatePaid = 42500.00;
    employees[empCount].monthlyBonus = 500.00;

    empCount++; // Increment counter (now 1)

    // 2. Insert Record for the Second Employee (Index 1)
    employees[empCount].firstName = "Jane";
    employees[empCount].lastName = "Smith";
    employees[empCount].personID = 1002;
    employees[empCount].deptID = "HR";
    employees[empCount].yearlySalary = 92000.00;
    employees[empCount].monthlySalary = 7666.67;
    employees[empCount].yearToDatePaid = 46000.00;
    employees[empCount].monthlyBonus = 600.00;

    empCount++; // Increment counter (now 2)

    // Call the function once, passing both the array and the counter
    printEmployeeRecords(employees, empCount);

    return 0;
}

// Function Implementation
// The array syntax `const employeeType employees[]` passes the array by reference automatically
void printEmployeeRecords(const employeeType employees[], int count)
{
    // Output formatting setup for currency display
    cout << fixed << setprecision(2);
    cout << "Total Employee Records Inserted: " << count << "\n\n";

    // The loop is now self-contained inside the function
    for (int i = 0; i < count; i++)
    {
        cout << "--- Employee #" << (i + 1) << " ---" << endl;
        cout << "Name: " << employees[i].firstName << " " << employees[i].lastName << endl;
        cout << "ID: " << employees[i].personID << " | Dept: " << employees[i].deptID << endl;
        cout << "Yearly Salary: $" << employees[i].yearlySalary << endl;
        cout << "Monthly Salary: $" << employees[i].monthlySalary << endl;
        cout << "Year-to-Date Paid: $" << employees[i].yearToDatePaid << endl;
        cout << "Monthly Bonus: $" << employees[i].monthlyBonus << endl;
        cout << endl;
    }
}