// compile: g++ Inheritance_Shape_Rect.cpp -o Inheritance_Shape_Rect.exe
// run: ./Inheritance_Shape_Rect.exe
#include <iostream>
using namespace std;

class Shape
{
public:
    Shape()
    {
        cout << "Shape created." << endl;
    }
};

class Rectangle : public Shape
{
protected:
    int width, height;

public:
    // Rectangle Constructor: Takes two parameters
    Rectangle(int w, int h) : Shape()
    {
        width = w;
        height = h;
        cout << "Rectangle initialized." << endl;
    }

    int getArea()
    {
        return width * height;
    }
};

int main()
{
    // Everything happens in one line!
    Rectangle myRect(5, 10);

    cout << "Rectangle Area: " << myRect.getArea() << endl;

    return 0;
}