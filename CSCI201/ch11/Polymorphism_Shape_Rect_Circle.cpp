#include <iostream>
using namespace std;

class Shape {
public:
    // Now returns a double instead of printing
    virtual double getArea() {
        return 0;
    }
};

class Rectangle : public Shape {
    int w, h;
public:
    Rectangle(int width, int height) : w(width), h(height) {}

    // Calculation only: No printing here
    double getArea() override {
        return w * h;
    }
};

class Circle : public Shape {
    int r;
public:
    Circle(int radius) : r(radius) {}

    // Calculation only: No printing here
    double getArea() override {
        return 3.14 * r * r;
    }
};

int main() {
    Rectangle myRect(10, 20);
    Circle myCircle(7);

    Shape& ref1 = myRect;
    Shape& ref2 = myCircle;

    // Now Main handles the "how" and "where" to show the data
    double area1 = ref1.getArea();
    double area2 = ref2.getArea();

    cout << "Rectangle Area: " << area1 << " units squared." << endl;
    cout << "Circle Area: " << area2 << " units squared." << endl;
    
    cout << "Total combined area: " << (area1 + area2) << endl;

    return 0;
}