// compile: g++ Rectangle_PassByReferencePointer.cpp -o Rectangle_PassByReferencePointer.exe
// run: ./Rectangle_PassByReferencePointer.exe

#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width;
    int height;
};

void update(Rectangle *&r)
{
    // Step 1: Modify the original Rectangle object.
    r->width = 100;
    r->height = 200;

    cout << "Inside update - After modifying original object: "
         << r->width << ", " << r->height << endl;

    // Step 2: Create a new Rectangle object.
    Rectangle *newRect = new Rectangle;
    newRect->width = 300;
    newRect->height = 400;

    // Step 3: Assign the new object's address to r.
    // Because r is a reference to the caller's pointer,
    // the caller's pointer is also updated.
    r = newRect;

    cout << "Inside update - After assigning new object: "
         << r->width << ", " << r->height << endl;
}

int main()
{
    // Create the original Rectangle object.
    Rectangle *rect = new Rectangle;
    rect->width = 10;
    rect->height = 5;

    cout << "In main - Before update: "
         << rect->width << ", " << rect->height << endl;

    update(rect);

    cout << "In main - After update: "
         << rect->width << ", " << rect->height << endl;

    // Delete the new object currently pointed to by rect.
    delete rect;

    return 0;
}
