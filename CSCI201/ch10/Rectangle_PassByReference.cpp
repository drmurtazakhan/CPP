// compile: g++ Rectangle_PassByReference.cpp -o Rectangle_PassByReference.exe
// run: ./Rectangle_PassByReference.exe

// 2. C++ — Pass-by-reference of an object
// The parameter Rectangle& r refers to the original object. No separate Rectangle copy is needed.

#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width;
    int height;
};

void update(Rectangle &r)
{ // Pass by reference
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

    // The original object has been modified.
    cout << "In main after update: "
         << rect.width << ", " << rect.height << endl;

    return 0;
}
