#include <iostream>
using namespace std;

// Base class: Person
class Person {
protected:
    string name;  // Accessible to subclasses
    int age;

public:
    // Constructor
    Person(string personName, int personAge) : name(personName), age(personAge) {}

    // Method
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class: Student
class Student : public Person {
private:
    string studentId;

public:
    // Constructor
    Student(string personName, int personAge, string id) 
        : Person(personName, personAge), studentId(id) {}

    // Overriding the display() method
    void display() override {
        Person::display();
        cout << "Student ID: " << studentId << endl;
    }
};

// Derived class: Teacher
class Teacher : public Person {
private:
    string staffId;
    double salary;

public:
    // Constructor
    Teacher(string personName, int personAge, string id, double sal) 
        : Person(personName, personAge), staffId(id), salary(sal) {}

    // Overriding the display() method
    void display() override {
        Person::display();
        cout << "Staff ID: " << staffId << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    // Creating a Person object
    Person p1("Ali", 30);
    
    // Creating a Student object
    Student s1("Maryam", 20, "S12345");

    // Creating a Teacher object
    Teacher t1("Dr. Ahmed", 45, "T67890", 55000);

    // Displaying information
    p1.display(); // Calls display() method from Person class
    cout << "----------------------" << endl;
    s1.display(); // Calls overridden display() method from Student class
    cout << "----------------------" << endl;
    t1.display(); // Calls overridden display() method from Teacher class

    return 0;
}
