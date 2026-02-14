// stack_unwinding_demo.cpp
#include <iostream>
#include <string>

using namespace std;

// A simple class to show when objects are created and destroyed
class Dummy {
public:
    string name;
    Dummy(string n) : name(n) { cout << "Creating " << name << endl; }
    ~Dummy() { cout << "Destroying " << name << " (Cleanup during unwinding)" << endl; }
};

void functionC() {
    Dummy objC("Object in Function C");
    cout << "Function C throwing an exception..." << endl;
    throw 99; // Exception starts here
}

void functionB() {
    Dummy objB("Object in Function B");
    functionC();
    cout << "This line in Function B will never run." << endl;
}

void functionA() {
    Dummy objA("Object in Function A");
    functionB();
}

int main() {
    try {
        functionA();
    }
    catch (int e) {
        cout << "\nCaught Exception: " << e << " in main()." << endl;
    }
    return 0;
}