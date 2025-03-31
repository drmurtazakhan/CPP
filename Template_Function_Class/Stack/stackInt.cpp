#include <iostream>
#include <vector>
using namespace std;

// Class for Stack of int
class Stack {
private:
    vector<int> elements;  // Vector to store stack elements

public:
    // Push an element onto the stack
    void push(int value) {
        elements.push_back(value);
    }

    // Pop the top element from the stack
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            cout << "Stack is empty! Cannot pop.\n";
        }
    }

    // Return the top element of the stack
    int top() {
        if (!elements.empty()) {
            return elements.back();
        }
        throw out_of_range("Stack is empty!");
    }

    // Check if the stack is empty
    bool isEmpty() {
        return elements.empty();
    }

    // Print the contents of the stack
    void printStack() {
        cout << "Stack contents (top to bottom): ";
        for (int i = elements.size() - 1; i >= 0; --i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

// Test program
int main() {
    Stack intStack;  // Stack of integers

    // Push elements onto the stack
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    // Print stack contents
    intStack.printStack();

    // Display the top element
    cout << "Top element: " << intStack.top() << endl;

    // Pop an element and print the stack again
    intStack.pop();
    intStack.printStack();

    // Pop another element and print the stack
    intStack.pop();
    intStack.printStack();

    // Try to pop from an empty stack
    intStack.pop();

    return 0;
}
