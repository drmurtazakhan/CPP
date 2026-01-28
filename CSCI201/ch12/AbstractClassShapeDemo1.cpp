#include <iostream>
using namespace std;

// --- Abstract Base Class ---
class Shape {
public:
    // This is now a Pure Virtual Function
    virtual int getArea() = 0; 

    // Regular virtual function with a body
    virtual void printInfo() {
        cout << "Shape Info: Generic Shape" << endl;
    }
};

// --- Concrete Derived Class ---
class Rectangle : public Shape {
private:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}

    // Forced to implement this because the parent's version is pure virtual
    int getArea() override {
        return width * height;
    }
};

int main() {
    // Shape s; // This line would now cause a compiler error!
    
    Rectangle myRect(10, 5);
    Shape* ptr = &myRect;

    cout << "Area: " << ptr->getArea() << endl;
    
    return 0;
}