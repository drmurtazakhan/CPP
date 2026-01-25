#include <iostream>
using namespace std;

class Shape {
public:
    // STATIC BINDING: No 'virtual' keyword.
    void printInfo() {
        cout << "Shape Info: Generic Shape" << endl;
    }

    // DYNAMIC BINDING: 'virtual' keyword.
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

    // Hiding the parent's info (Static)
    void printInfo() {
        cout << "Shape Info: Rectangle (" << width << "x" << height << ")" << endl;
    }

    // Overriding the parent's area (Dynamic)
    int getArea() override {
        return width * height;
    }
};

int main() {
    // 1. Create a Rectangle object
    Rectangle myRect(10, 5); 

    // 2. Create a Base Pointer pointing to our Rectangle
    Shape* ptr = &myRect;

    cout << "--- STATIC BINDING TEST ---" << endl;
    // Uses the Pointer Type (Shape). It ignores the Rectangle logic.
    ptr->printInfo(); 

    cout << "\n--- DYNAMIC BINDING TEST ---" << endl;
    // Uses the Actual Object (Rectangle) because of 'virtual'.
    cout << "Area calculated: " << ptr->getArea() << endl;

    return 0;
}