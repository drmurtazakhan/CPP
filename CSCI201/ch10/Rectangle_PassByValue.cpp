// compile: g++ Rectangle_PassByValue.cpp -o Rectangle_PassByValue.exe
// run: ./Rectangle_PassByValue.exe

// 1. C++ — Pass-by-value of an object
// A copy of the entire Rectangle object is passed to the function. Changes to the copy do not affect the original object.

#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width;
    int height;
};

void update(Rectangle r)
{ // Pass by value: r is a copy
    r.width = 100;
    r.height = 200;

    cout << "Inside function: "
         << r.width << ", " << r.height << endl;
}

int main()
{
    Rectangle rect;
    rect.width = 10;
    rect.height = 5;

    cout << "In main before update: "
         << rect.width << ", " << rect.height << endl;

    update(rect);

    // The original object remains unchanged.
    cout << "In main after update: "
         << rect.width << ", " << rect.height << endl;

    return 0;
}
