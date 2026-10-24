// compile: g++ Rectangle_PassByValuePointer.cpp -o Rectangle_PassByValuePointer.exe
// run: ./Rectangle_PassByValuePointer.exe

// 3. C++ — Pass-by-value of a pointer
// The function receives a copy of the pointer containing the object's address. Both pointers can access the same object, but reassigning the local pointer does not change the caller's pointer.

#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width;
    int height;
};

void update(Rectangle *r)
{ // Pointer passed by value
    r->width = 100;
    r->height = 200;

    cout << "Inside function changed original: "
         << r->width << ", " << r->height << endl;

    // Create a new Rectangle and assign its address
    // to the local pointer r.
    Rectangle *newRect = new Rectangle;
    newRect->width = 300;
    newRect->height = 400;

    r = newRect; // Only the local pointer changes

    cout << "Inside function new rectangle: "
         << r->width << ", " << r->height << endl;

    delete newRect;
}

int main()
{
    Rectangle rect;
    rect.width = 10;
    rect.height = 5;

    cout << "In main before update: "
         << rect.width << ", " << rect.height << endl;

    update(&rect); // Pass the address of rect

    // rect was modified before r was reassigned.
    // Reassigning r did not change rect.
    cout << "In main after update: "
         << rect.width << ", " << rect.height << endl;

    return 0;
}
