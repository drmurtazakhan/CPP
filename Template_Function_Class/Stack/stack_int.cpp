#include <iostream>
#include <vector>

using namespace std;

class IntegerStack {
private:
    vector<int> elements;  // vector to store int elements

public:
    void push(int value) {  // push an element onto the stack
        elements.push_back(value);
    }

    void pop() {  // Remove the top element
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            cout << "Stack is empty! Cannot pop.\n";
        }
    }

    int top() {  // Return the top element
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
    IntegerStack intStack;  // Create a Stack object for integers

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    intStack.printStack();

    cout << "Top element: " << intStack.top() << endl;

    intStack.pop();
    intStack.printStack();

    return 0;
}
