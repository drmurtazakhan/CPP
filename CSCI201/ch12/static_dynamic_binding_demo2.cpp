// compile: g++ static_dynamic_binding_demo2.cpp -o static_dynamic_binding_demo2.exe
// run: ./static_dynamic_binding_demo2.exe

#include <iostream>
using namespace std;

class Shape
{
public:
    // Dynamic binding: uses 'virtual'
    virtual double getArea()
    {
        return 0;
    }

    // STATIC BINDING: No 'virtual' keyword.
    void printInfo()
    {
        cout << "Shape Info: Generic Shape" << endl;
    }
};

class Rectangle : public Shape
{
    int w, h;

public:
    // constructor using a member initializer list:
    Rectangle(int width, int height) : w(width), h(height) {}

    // Calculation only: No printing here
    double getArea() override
    {
        return w * h;
    }

    // Hiding the parent's info (Static)
    void printInfo()
    {
        cout << "Shape Info: Rectangle (" << w << " x " << h << ")" << endl;
    }
};

class Circle : public Shape
{
    int r;

public:
    Circle(int radius) : r(radius) {}

    // Calculation only: No printing here
    double getArea() override
    {
        return 3.14 * r * r;
    }

    // Hiding the parent's info (Static)
    void printInfo()
    {
        cout << "Shape Info: Circle (Radius: " << r << ")" << endl;
    }
};

int main()
{
    Rectangle myRect(10, 20);
    Circle myCircle(7);

    Shape *ptr1 = &myRect;
    Shape *ptr2 = &myCircle;

    // Static Binding Calls: Checked at compile-time based on pointer type (Shape*)
    ptr1->printInfo();
    ptr2->printInfo();
    cout << endl;

    // Direct calls resolve statically using the exact object type
    myRect.printInfo();   // Calls Rectangle::printInfo()
    myCircle.printInfo(); // Calls Circle::printInfo()

    cout << endl;

    // Dynamic Binding Calls: Checked at runtime based on actual object type
    double area1 = ptr1->getArea();
    double area2 = ptr2->getArea();

    cout << "Rectangle Area: " << area1 << " units squared." << endl;
    cout << "Circle Area: " << area2 << " units squared." << endl;

    cout << "Total combined area: " << (area1 + area2) << endl;

    return 0;
}