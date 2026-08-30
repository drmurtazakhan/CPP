// compile with: g++ -std=c++17 RectangleNonInline.cpp -o RectangleNonInline.exe
// run with: ./RectangleNonInline.exe
#include <iostream>
using namespace std;

class Rectangle
{
private:
    double length, width;

public:
    double area(); // Function declaration

    void setDimensions(double l, double w)
    {
        length = l;
        width = w;
    }
};

// Function defined outside the class
double Rectangle::area()
{
    return length * width;
}

int main()
{
    Rectangle r;
    r.setDimensions(10, 5);

    cout << "Area = " << r.area() << endl;

    return 0;
}