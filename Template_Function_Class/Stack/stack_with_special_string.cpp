#include <iostream>
#include <vector>
#include <algorithm>  // For std::transform
#include <cctype>     // For std::toupper

using namespace std;

// Template class for a Stack
template <typename T>
class Stack {
private:
    vector<T> elements;  // vector to store elements of type T

public:
    void push(T value) {  // Push an element onto the stack
        elements.push_back(value);
    }

    void pop() {  // Remove the top element
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            cout << "Stack is empty! Cannot pop.\n";
        }
    }

    T top() {  // Return the top element
        if (!elements.empty()) {
            return elements.back();
        }
        throw out_of_range("Stack is empty!");
    }

    bool isEmpty() {  // Check if the stack is empty
        return elements.empty();
    }

    void printStack() {  // Print stack elements
        cout << "Stack contents (top to bottom): ";
        for (int i = elements.size() - 1; i >= 0; --i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

// Specialized Stack class for strings
template <>
class Stack<string> {
private:
    vector<string> elements;  // vector to store elements of type string

public:
    // Override the push method for strings to convert them to uppercase
    void push(string value) {
        // Convert string to uppercase
        transform(value.begin(), value.end(), value.begin(), ::toupper);
        // Add the uppercase string to the stack
        elements.push_back(value);
    }

    void pop() {  // Remove the top element
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            cout << "Stack is empty! Cannot pop.\n";
        }
    }

    string top() {  // Return the top element
        if (!elements.empty()) {
            return elements.back();
        }
        throw out_of_range("Stack is empty!");
    }

    bool isEmpty() {  // Check if the stack is empty
        return elements.empty();
    }

    void printStack() {  // Print stack elements
        cout << "Stack contents (top to bottom): ";
        for (int i = elements.size() - 1; i >= 0; --i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

// Test program
int main() {
    Stack<int> intStack;  // create object of Stack<int>

    intStack.push(10); // Call push method of Stack<int>
    intStack.push(20);
    intStack.push(30);

    intStack.printStack();  // Display stack

    cout << "Top element: " << intStack.top() << endl;

    intStack.pop();
    intStack.printStack();

    // Using Stack<string> and the specialized push method
    Stack<string> strStack;  // create object of Stack<string>
    strStack.push("hello");  // call push method of Stack<string>
    strStack.push("world");
    strStack.printStack();

    return 0;
}
