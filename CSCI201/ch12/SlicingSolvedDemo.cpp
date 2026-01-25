#include <iostream>
using namespace std;

class Shape {
public:
    virtual int getArea() {
        return 0; 
    }

    // Virtual destructor - ALWAYS in the Base class
    virtual ~Shape() {
        cout << "Shape Destructor Executing..." << endl;
    }
};

class Rectangle : public Shape {
private:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}

    // Destructor - Automatically becomes virtual because the parent's is virtual
    ~Rectangle() {
        cout << "Rectangle Destructor Executing..." << endl;
    }

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

    //4. Print addresses to show both pointers point to the same object
    cout << "\nAddress in ptr1:          " << ptr1 << endl;
    cout << "Address in ptr2:          " << ptr2 << endl;

    return 0;
}