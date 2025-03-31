#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack {
private:
    vector<int> intElements;     // Stack for integer elements
    vector<double> doubleElements; // Stack for double elements
    vector<string> stringElements; // Stack for string elements

public:
    // Overloaded push function for int
    void push(int value) {
        intElements.push_back(value);
    }

    // Overloaded push function for double
    void push(double value) {
        doubleElements.push_back(value);
    }

    // Overloaded push function for string
    void push(const string& value) {
        stringElements.push_back(value);
    }

    // Pop function for int
    void popInt() {
        if (!intElements.empty()) {
            intElements.pop_back();
        } else {
            cout << "Int stack is empty! Cannot pop.\n";
        }
    }

    // Pop function for double
    void popDouble() {
        if (!doubleElements.empty()) {
            doubleElements.pop_back();
        } else {
            cout << "Double stack is empty! Cannot pop.\n";
        }
    }

    // Pop function for string
    void popString() {
        if (!stringElements.empty()) {
            stringElements.pop_back();
        } else {
            cout << "String stack is empty! Cannot pop.\n";
        }
    }

    // Top function for int
    int topInt() {
        if (!intElements.empty()) {
            return intElements.back();
        }
        throw out_of_range("Int stack is empty!");
    }

    // Top function for double
    double topDouble() {
        if (!doubleElements.empty()) {
            return doubleElements.back();
        }
        throw out_of_range("Double stack is empty!");
    }

    // Top function for string
    string topString() {
        if (!stringElements.empty()) {
            return stringElements.back();
        }
        throw out_of_range("String stack is empty!");
    }

    // Check if int stack is empty
    bool isEmptyInt() {
        return intElements.empty();
    }

    // Check if double stack is empty
    bool isEmptyDouble() {
        return doubleElements.empty();
    }

    // Check if string stack is empty
    bool isEmptyString() {
        return stringElements.empty();
    }

    // Print int stack
    void printIntStack() {
        cout << "Int Stack (top to bottom): ";
        for (int i = intElements.size() - 1; i >= 0; --i) {
            cout << intElements[i] << " ";
        }
        cout << endl;
    }

    // Print double stack
    void printDoubleStack() {
        cout << "Double Stack (top to bottom): ";
        for (int i = doubleElements.size() - 1; i >= 0; --i) {
            cout << doubleElements[i] << " ";
        }
        cout << endl;
    }

    // Print string stack
    void printStringStack() {
        cout << "String Stack (top to bottom): ";
        for (int i = stringElements.size() - 1; i >= 0; --i) {
            cout << stringElements[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Stack for int
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.printIntStack();

    // Stack for double
    stack.push(3.14);
    stack.push(2.718);
    stack.printDoubleStack();

    // Stack for string
    stack.push("Hello");
    stack.push("World");
    stack.printStringStack();

    return 0;
}
