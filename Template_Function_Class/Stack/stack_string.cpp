#include <iostream>
#include <vector>

using namespace std;

class StringStack {
private:
    vector<string> elements;  // vector to store string elements

public:
    void push(string value) {  // push an element onto the stack
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
    StringStack strStack;  // Create a Stack object for strings

    strStack.push("Hello");
    strStack.push("World");
    strStack.push("2025");

    strStack.printStack();  // Display stack

    cout << "Top element: " << strStack.top() << endl;

    strStack.pop();
    strStack.printStack();

    return 0;
}
