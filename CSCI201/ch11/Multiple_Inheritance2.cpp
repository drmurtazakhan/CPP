#include <iostream>
using namespace std;

// Base class 1: Shape (Now holds the data and setters)
class Shape {
protected:
    int width, height; // Moved here so setters can access them

public:
    Shape() {
        cout << "Shape base initialized." << endl;
    }

    // Setter methods added here
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
};

// Base class 2: PaintCost
class PaintCost {
public:
    int getCost(int area) {
        return area * 70;
    }
};

// Derived class inherits from BOTH Shape and PaintCost
class Rectangle : public Shape, public PaintCost {
public:
    // Rectangle Constructor
    Rectangle(int w, int h) {
        width = w;
        height = h;
        cout << "Rectangle initialized with dimensions." << endl;
    }

    int getArea() {
        return width * height;
    }
};

int main() {
    // 1. Create the object
    Rectangle rect(5, 7);
    cout << "Initial area: " << rect.getArea() << endl;

    // 2. Use setters inherited from Shape to change dimensions
    rect.setWidth(10);
    rect.setHeight(10);

    // 3. Calculate new area and cost
    int area = rect.getArea();
    cout << "Updated area: " << area << endl;
    cout << "Total paint cost: $" << rect.getCost(area) << endl;

    return 0;
}