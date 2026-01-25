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
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    int getArea() override {
        return width * height;
    }
};

// The Formal Parameter (Base Type Reference)
void printArea(Shape &s) {
    cout << "Area result: " << s.getArea() << endl;
}

int main() {
    Rectangle myRect(10, 5); // Width 10, Height 5

    // Concept 1: Passing the original object
    cout << "--- Concept 1: Passing Derived to Base Parameter ---" << endl;
    printArea(myRect); 

    // Concept 2: Creating a copy in a base object
    cout << "\n--- Concept 2: Copying Derived into Base Object ---" << endl;
    Shape genericShape = myRect; // Slicing happens here!
    
    // Now passing the sliced copy to the same function
    printArea(genericShape); 

    cout << "\nAddress of myRect:       " << &myRect << endl;
    cout << "Address of genericShape: " << &genericShape << endl;

    cout << "\nSize of myRect: " << sizeof(myRect) << " bytes" << endl;
    cout << "Size of genericShape: " << sizeof(genericShape) << " bytes" << endl;

    return 0;
}