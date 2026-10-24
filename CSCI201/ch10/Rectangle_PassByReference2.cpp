// compile: g++ Rectangle_PassByReference2.cpp -o Rectangle_PassByReference2.exe
// run: ./Rectangle_PassByReference2.exe

// 4. C++ — Pass-by-reference of an object with reassignment
// The parameter Rectangle& r refers to the original object. No separate Rectangle copy is created.

#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width;
    int height;
};

void update(Rectangle &r)
{
    r.width = 100;
    r.height = 200;

    cout << "Inside function changed original: "
         << r.width << ", " << r.height << endl;

    Rectangle newRect;
    newRect.width = 300;
    newRect.height = 400;

    // A reference cannot be redirected to another object after initialization. Instead, this statement copies the values of newRect into the original object rect, because r is an alias for rect.

    r = newRect; // Assign the new object's values to the original object
    cout << "Inside function new rectangle: "
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

    cout << "In main after update: "
         << rect.width << ", " << rect.height << endl;

    return 0;
}