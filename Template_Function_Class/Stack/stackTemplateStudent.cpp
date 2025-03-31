#include <iostream>
#include <vector>

using namespace std;

// Student class
class Student
{
public:
    string name;
    int id;

    // Constructor
    Student(string n, int i) : name(n), id(i) {}

    // Display function instead of overloading <<
    void display() const
    {
        cout << "Student: " << name << ", ID: " << id;
    }
};

// Template class for Stack
template <typename T>
class Stack
{
private:
    vector<T> elements; // Stores stack elements

public:
    // Push element onto stack
    void push(const T &value)
    {
        elements.push_back(value);
    }

    // Pop top element from stack
    void pop()
    {
        if (!elements.empty())
        {
            elements.pop_back();
        }
        else
        {
            cout << "Stack is empty! Cannot pop.\n";
        }
    }

    // Return the top element
    const T &top() const
    {
        if (!elements.empty())
        {
            return elements.back();
        }
        throw out_of_range("Stack is empty!");
    }

    // Check if stack is empty
    bool isEmpty() const
    {
        return elements.empty();
    }

    // Print stack contents
    void printStack() const
    {
        cout << "Stack contents (top to bottom):\n";
        for (int i = elements.size() - 1; i >= 0; --i)
        {
            printElement(elements[i]); // Calls helper function to print different types
            cout << endl;
        }
        cout << endl;
    }

private:
    // Helper function to print elements (handles Student separately)
    void printElement(const T &element) const
    {
        cout << element; // Works for int, double, and string
    }

    // Specialization for Student class (overloaded function inside class)
    void printElement(const Student &s) const
    {
        s.display(); // Calls Student's display() method
    }
};

// Test program
int main()
{
    // Stack of int
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.printStack();
    cout << "Top element: " << intStack.top() << endl;
    intStack.pop();
    intStack.printStack();

    // Stack of double
    Stack<double> doubleStack;
    doubleStack.push(1.1);
    doubleStack.push(2.2);
    doubleStack.push(3.3);
    doubleStack.printStack();
    cout << "Top element: " << doubleStack.top() << endl;
    doubleStack.pop();
    doubleStack.printStack();

    // Stack of string
    Stack<string> strStack;
    strStack.push("Harper");
    strStack.push("College");
    strStack.push("CS Department");
    strStack.printStack();
    cout << "Top element: " << strStack.top() << endl;
    strStack.pop();
    strStack.printStack();

    // Stack of Student
    Stack<Student> studentStack;
    studentStack.push(Student("Alice", 545464));
    studentStack.push(Student("Bob", 123456));
    studentStack.push(Student("Charlie", 987654));
    studentStack.printStack();
    cout << "Top Student: ";
    studentStack.top().display(); // Explicitly call display() for Student
    cout << endl;
    studentStack.pop();
    studentStack.printStack();

    return 0;
}
