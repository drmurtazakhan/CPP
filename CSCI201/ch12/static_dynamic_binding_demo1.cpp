#include <iostream>
using namespace std;

class Shape {
public:
    // Virtual function for Dynamic Binding
    virtual int getArea() {
        return 0;
    }
};

class Rectangle : public Shape {
private:
    int width, height;

public:
    // Constructor to set unique dimensions
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    // Overriding the area formula
    int getArea() override {
        return width * height;
    }
};

int main() {
    // We create a Rectangle with specific dimensions
    Rectangle myRect(10, 5); 

    // Base pointer pointing to the Derived object
    Shape* ptr = &myRect;

    // DYNAMIC BINDING: 
    // Even though ptr is a "Shape*", it calls Rectangle's getArea()
    cout << "Area via Pointer: " << ptr->getArea() << endl;

    return 0;
}