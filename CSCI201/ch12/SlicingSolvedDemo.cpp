#include <iostream>
using namespace std;

class Shape {
public:
    virtual int getArea() {
        return 0; 
    }
};

class Rectangle : public Shape {
private:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int getArea() override {
        return width * height;
    }
};

// Formal Parameter using a Pointer to the Base type
void printArea(Shape* s) {
    if (s != nullptr) {
        cout << "Area result: " << s->getArea() << endl;
    }
}

int main() {
    // 1. Create the original Derived object
    Rectangle myRect(10, 5);

    // 2. Base Class Pointer pointing to Derived Object
    // Concept 1: No slicing occurs because it's just an address.
    Shape* ptr1 = &myRect;
    cout << "--- Pointer 1 (Base Type Pointer) ---" << endl;
    printArea(ptr1); 

    // 3. Derived Class Pointer pointing to Derived Object
    // Solving the slicing problem: ptr2 also points to the original memory.
    Rectangle* ptr2 = &myRect;
    cout << "\n--- Pointer 2 (Derived Type Pointer) ---" << endl;
    printArea(ptr2); // C++ allows passing Rectangle* where Shape* is expected.

    return 0;
}