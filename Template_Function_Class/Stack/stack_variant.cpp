#include <iostream>
#include <vector>
#include <variant>

using namespace std;

// Define a template class where T is a std::variant of multiple types
template <typename... Types>
class Stack {
private:
    vector<variant<Types...>> elements;  // Vector to store elements of different types

public:
    void push(variant<Types...> value) {  // Push an element onto the stack
        elements.push_back(value);
    }

    void pop() {  // Remove the top element
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            cout << "Stack is empty! Cannot pop.\n";
        }
    }

    variant<Types...> top() {  // Return the top element
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
            visit([](auto&& value) { cout << value << " "; }, elements[i]);
        }
        cout << endl;
    }
};

// Test program
int main() {
    Stack<int, double, string> multiStack;  // Single Stack object for multiple types

    multiStack.push(10);         // Store int
    multiStack.push(3.14);       // Store double
    multiStack.push("Hello");    // Store string

    multiStack.printStack();     // Print stack

    cout << "Top element: ";
    visit([](auto&& value) { cout << value << endl; }, multiStack.top());

    multiStack.pop();
    multiStack.printStack();

    return 0;
}
