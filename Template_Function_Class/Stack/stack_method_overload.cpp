#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack {
private:
    vector<int> intStack;
    vector<double> doubleStack;
    vector<string> stringStack;

public:
    // Push methods (Overloaded for int, double, and string)
    void push(int value) {
        intStack.push_back(value);
    }

    void push(double value) {
        doubleStack.push_back(value);
    }

    void push(const string& value) {
        stringStack.push_back(value);
    }

    // Pop methods (Overloaded for int, double, and string)
    void popInt() {
        if (!intStack.empty()) {
            intStack.pop_back();
        } else {
            cout << "Integer Stack is empty! Cannot pop.\n";
        }
    }

    void popDouble() {
        if (!doubleStack.empty()) {
            doubleStack.pop_back();
        } else {
            cout << "Double Stack is empty! Cannot pop.\n";
        }
    }

    void popString() {
        if (!stringStack.empty()) {
            stringStack.pop_back();
        } else {
            cout << "String Stack is empty! Cannot pop.\n";
        }
    }

    // Print methods (Overloaded for int, double, and string)
    void printStackInt() {
        cout << "Integer Stack (top to bottom): ";
        for (int i = intStack.size() - 1; i >= 0; --i) {
            cout << intStack[i] << " ";
        }
        cout << endl;
    }

    void printStackDouble() {
        cout << "Double Stack (top to bottom): ";
        for (int i = doubleStack.size() - 1; i >= 0; --i) {
            cout << doubleStack[i] << " ";
        }
        cout << endl;
    }

    void printStackString() {
        cout << "String Stack (top to bottom): ";
        for (int i = stringStack.size() - 1; i >= 0; --i) {
            cout << stringStack[i] << " ";
        }
        cout << endl;
    }
};

// Test program
int main() {
    Stack stack;  // Single Stack object handling different data types

    // Testing Integer Stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.printStackInt();
    stack.popInt();
    stack.printStackInt();

    // Testing Double Stack
    stack.push(10.5);
    stack.push(20.7);
    stack.push(30.9);
    stack.printStackDouble();
    stack.popDouble();
    stack.printStackDouble();

    // Testing String Stack
    stack.push("Harper");
    stack.push("College");
    stack.printStackString();
    stack.popString();
    stack.printStackString();

    return 0;
}
