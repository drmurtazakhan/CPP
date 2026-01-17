#include <iostream>
using namespace std;

// Base class 1: Shape (No parameters)
class Shape {
public:
    Shape() {
        cout << "Shape base initialized." << endl;
    }
};

// Base class 2: PaintCost
class PaintCost {
public:
    // No constructor needed here, just a utility method
    int getCost(int area) {
        return area * 70;
    }
};

// Derived class using Multiple Inheritance
// It inherits from BOTH Shape and PaintCost
class Rectangle : public Shape, public PaintCost {
protected:
    int width, height;

public:
    // Rectangle Constructor: Initializes width and height
    // It also calls the Shape constructor automatically
    Rectangle(int w, int h) : Shape() {
        width = w;
        height = h;
        cout << "Rectangle initialized with dimensions." << endl;
    }

    int getArea() {
        return width * height;
    }
};

int main() {
    // We create the object in one line using the constructor
    Rectangle rect(5, 7);

    int area = rect.getArea();

    cout << "Total area: " << area << endl;

    // We use the method inherited from PaintCost
    cout << "Total paint cost: $" << rect.getCost(area) << endl;

    return 0;
}