// compile: g++ array_list_template_Employee.cpp -o array_list_template_Employee.exe
// run: ./array_list_template_Employee.exe

// This program demonstrates a class template that can store Employee objects in an array list.

#include <iostream>
#include <string>
using namespace std;

// Employee is the type that we will store in our array list
class Employee
{
private:
    string name;
    double salary;

public:
    // Constructor
    Employee(string n = "", double s = 0)
        : name(n), salary(s) {}

    // Allows cout to print an Employee object
    friend ostream &operator<<(ostream &out, const Employee &emp)
    {
        out << emp.name << " $" << emp.salary;
        return out;
    }
};

// Class template
// elemType is a placeholder for the type of elements in the list
template <class elemType>
class arrayListType
{
private:
    elemType *list; // Pointer to the dynamically allocated array
    int length;     // Number of elements currently in the list
    int maxSize;    // Maximum number of elements the list can hold

public:
    // Constructor
    // Creates a dynamic array of elemType objects
    arrayListType(int size = 100)
    {
        maxSize = size;
        length = 0;

        // elemType could be int, string, Employee, etc.
        list = new elemType[maxSize];
    }

    // Destructor
    // Releases the dynamically allocated array
    ~arrayListType()
    {
        delete[] list;
    }

    // Insert an element at the end of the list
    void insert(const elemType &insertItem)
    {
        // Make sure there is room in the array
        if (length < maxSize)
        {
            list[length] = insertItem;
            length++;
        }
        else
        {
            cout << "List is full!" << endl;
        }
    }

    // Print all elements in the list
    void print() const
    {
        for (int i = 0; i < length; i++)
        {
            // This works for Employee because we defined operator<<
            cout << list[i] << endl;
        }
    }
};

int main()
{
    // Employee becomes the elemType of arrayListType
    arrayListType<Employee> employeeList(5);

    // Insert Employee objects into the list
    employeeList.insert(Employee("Ali", 50000));
    employeeList.insert(Employee("Sara", 60000));
    employeeList.insert(Employee("John", 50000));

    // Print the Employee objects
    cout << "Employees:" << endl;
    employeeList.print();

    return 0;
}
