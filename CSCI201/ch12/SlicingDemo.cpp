#include <iostream>
using namespace std;

class Shape {
public:
    // Virtual method to be overridden
    virtual int getArea() {
        return 0; 
    }
};

class Rectangle : public Shape {
private:
    int width, height;

public:
    // 1. Constructor to initialize width and height
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    // 2. Overriding getArea() to compute width * height
    int getArea() override {
        return width * height;
    }
};

// CONCEPT 1: Formal parameter of the base class type (passed by reference)
void printArea(Shape &s) {
    cout << "Area result: " << s.getArea() << endl;
}

int main() {
    // Creating a Rectangle object with width 10 and height 5
    Rectangle myRect(10, 5);

    cout << "--- Concept 1: Passing Derived to Base Parameter ---" << endl;
    // We pass 'myRect' into a function asking for a 'Shape'.
    // Because it's a reference, the 'identity' and 'data' stay intact.
    printArea(myRect); 

    cout << "\n--- Concept 2: Copying Derived into Base Object ---" << endl;
    // Values are copied into a brand new Shape object.
    Shape genericShape = myRect; 

    // Because 'genericShape' is just a Shape, it has no width or height variables!
    // The Rectangle parts were "sliced" away during the copy.
    cout << "Area result: " << genericShape.getArea() << endl;

    return 0;
}