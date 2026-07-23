// This program demonstrates the use of structs that contain other structs as members.
// compile: g++  StructsWithStruct.cpp -o StructsWithStruct.exe
// run: ./StructsWithStruct.exe

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// 1. Define the sub-category structs exactly as shown in the image
struct nameType
{
    string first;
    string middle;
    string last;
};

struct addressType
{
    string address1;
    string address2;
    string city;
    string state;
    string zip;
};

struct dateType
{
    int month;
    int day;
    int year;
};

struct contactType
{
    string phone;
    string cellphone;
    string fax;
    string pager;
    string email;
};

// 2. Define the main employeeType struct that contains the other structs
struct employeeType
{
    nameType name;
    string empID;
    addressType address;
    dateType hireDate;
    dateType quitDate;
    contactType contact;
    string deptID;
    double salary;
};

// Function Prototype: Accepts the array of employees and its active size
void printEmployeeRecords(const employeeType list[], int size);

int main()
{
    // Declare an array to hold 3 employee records
    const int MAX_EMPLOYEES = 3;
    employeeType companyEmployees[MAX_EMPLOYEES];
    int empCount = 0;

    // --- Record 1: First Employee ---
    companyEmployees[empCount].name.first = "Alice";
    companyEmployees[empCount].name.middle = "Marie";
    companyEmployees[empCount].name.last = "Smith";
    companyEmployees[empCount].empID = "E-101";
    companyEmployees[empCount].address.address1 = "123 Main St";
    companyEmployees[empCount].address.address2 = "Apt 4B";
    companyEmployees[empCount].address.city = "Crown Point";
    companyEmployees[empCount].address.state = "IN";
    companyEmployees[empCount].address.zip = "46307";
    companyEmployees[empCount].hireDate.month = 3;
    companyEmployees[empCount].hireDate.day = 14;
    companyEmployees[empCount].hireDate.year = 2021;
    companyEmployees[empCount].quitDate.month = 0; // 0 means active
    companyEmployees[empCount].quitDate.day = 0;
    companyEmployees[empCount].quitDate.year = 0;
    companyEmployees[empCount].contact.phone = "219-555-0192";
    companyEmployees[empCount].contact.cellphone = "219-555-0199";
    companyEmployees[empCount].contact.fax = "N/A";
    companyEmployees[empCount].contact.pager = "N/A";
    companyEmployees[empCount].contact.email = "alice.smith@corp.com";
    companyEmployees[empCount].deptID = "IT";
    companyEmployees[empCount].salary = 85000.00;
    empCount++; // Count is now 1

    // --- Record 2: Second Employee ---
    companyEmployees[empCount].name.first = "Bob";
    companyEmployees[empCount].name.middle = "Alan";
    companyEmployees[empCount].name.last = "Jones";
    companyEmployees[empCount].empID = "E-102";
    companyEmployees[empCount].address.address1 = "456 Oak Rd";
    companyEmployees[empCount].address.address2 = "";
    companyEmployees[empCount].address.city = "Merrillville";
    companyEmployees[empCount].address.state = "IN";
    companyEmployees[empCount].address.zip = "46410";
    companyEmployees[empCount].hireDate.month = 11;
    companyEmployees[empCount].hireDate.day = 1;
    companyEmployees[empCount].hireDate.year = 2018;
    companyEmployees[empCount].quitDate.month = 5;
    companyEmployees[empCount].quitDate.day = 22;
    companyEmployees[empCount].quitDate.year = 2025;
    companyEmployees[empCount].contact.phone = "219-555-0143";
    companyEmployees[empCount].contact.cellphone = "219-555-0144";
    companyEmployees[empCount].contact.fax = "219-555-0145";
    companyEmployees[empCount].contact.pager = "N/A";
    companyEmployees[empCount].contact.email = "bob.jones@corp.com";
    companyEmployees[empCount].deptID = "HR";
    companyEmployees[empCount].salary = 62000.00;
    empCount++; // Count is now 2

    // --- Record 3: Third Employee ---
    companyEmployees[empCount].name.first = "Charlie";
    companyEmployees[empCount].name.middle = "Vane";
    companyEmployees[empCount].name.last = "Thaw";
    companyEmployees[empCount].empID = "E-103";
    companyEmployees[empCount].address.address1 = "789 Pine Ave";
    companyEmployees[empCount].address.address2 = "Suite 10";
    companyEmployees[empCount].address.city = "Chicago";
    companyEmployees[empCount].address.state = "IL";
    companyEmployees[empCount].address.zip = "60601";
    companyEmployees[empCount].hireDate.month = 6;
    companyEmployees[empCount].hireDate.day = 19;
    companyEmployees[empCount].hireDate.year = 2023;
    companyEmployees[empCount].quitDate.month = 0;
    companyEmployees[empCount].quitDate.day = 0;
    companyEmployees[empCount].quitDate.year = 0;
    companyEmployees[empCount].contact.phone = "312-555-0711";
    companyEmployees[empCount].contact.cellphone = "312-555-0712";
    companyEmployees[empCount].contact.fax = "N/A";
    companyEmployees[empCount].contact.pager = "312-555-0713";
    companyEmployees[empCount].contact.email = "charlie.t@corp.com";
    companyEmployees[empCount].deptID = "Finance";
    companyEmployees[empCount].salary = 95000.00;
    empCount++; // Count is now 3

    // Call the helper function to print everything cleanly
    printEmployeeRecords(companyEmployees, empCount);

    return 0;
}

// Function Implementation
void printEmployeeRecords(const employeeType list[], int size)
{
    cout << fixed << setprecision(2);
    cout << "=========================================\n";
    cout << "       EMPLOYEE DATABASE REPORT          \n";
    cout << "=========================================\n\n";

    for (int i = 0; i < size; i++)
    {
        cout << "Employee ID: " << list[i].empID << endl;
        cout << "Full Name:   " << list[i].name.last << ", "
             << list[i].name.first << " " << list[i].name.middle << endl;

        cout << "Address:     " << list[i].address.address1;
        if (!list[i].address.address2.empty())
        {
            cout << ", " << list[i].address.address2;
        }
        cout << ", " << list[i].address.city << ", "
             << list[i].address.state << " " << list[i].address.zip << endl;

        cout << "Contact:     Email: " << list[i].contact.email
             << " | Cell: " << list[i].contact.cellphone << endl;

        cout << "Dates:       Hired: " << list[i].hireDate.month << "/"
             << list[i].hireDate.day << "/" << list[i].hireDate.year;

        if (list[i].quitDate.year != 0)
        {
            cout << " | Quit: " << list[i].quitDate.month << "/"
                 << list[i].quitDate.day << "/" << list[i].quitDate.year;
        }
        else
        {
            cout << " | Status: Active";
        }
        cout << endl;

        cout << "Department:  " << list[i].deptID
             << " | Salary: $" << list[i].salary << endl;
        cout << "-----------------------------------------\n";
    }
}