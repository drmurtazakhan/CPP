#include <iostream>
using namespace std;

class Shape {
public:
    Shape() {
        cout << "Shape created." << endl;
    }
};

class Rectangle : public Shape {
protected:
    int width, height;

public:
    // Rectangle Constructor: Takes two parameters
    Rectangle(int w, int h) : Shape() {
        width = w;
        height = h;
        cout << "Rectangle initialized." << endl;
    }

    int getArea() {
        return width * height;
    }
};

class Square : public Rectangle {
public:
    // Square Constructor: Takes ONE parameter
    // It passes that 's' twice to the Rectangle constructor
    Square(int s) : Rectangle(s, s) {
        cout << "Square initialized." << endl;
    }
};

int main() {
    // Everything happens in one line!
    Rectangle myRect(5, 10);
    Square mySquare(6);

    cout << "Rectangle Area: " << myRect.getArea() << endl;
    cout << "Square Area: " << mySquare.getArea() << endl;

    return 0;
}