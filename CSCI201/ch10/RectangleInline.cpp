// compile with: g++ -std=c++17 RectangleInline.cpp -o RectangleInline.exe
// run with: ./RectangleInline.exe

#include <iostream>
using namespace std;

class Rectangle
{
private:
    double length, width;

public:
    // Inline function
    double area()
    {
        return length * width;
    }

    void setDimensions(double l, double w)
    {
        length = l;
        width = w;
    }
};

int main()
{
    Rectangle r;
    r.setDimensions(10, 5);

    cout << "Area = " << r.area() << endl;

    return 0;
}