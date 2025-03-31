#include <iostream>
#include <vector>

using namespace std;

// Template class for a Stack
template <typename T>
class Stack {
private:
    vector<T> elements;  // vector to store elements of type T

public: // Start of public members
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

    Stack<string> strStack; // create object of Stack<string>
    
    strStack.push("Harper"); // call push method of Stack<string>
    strStack.push("College");
    strStack.printStack();


    return 0;
}
