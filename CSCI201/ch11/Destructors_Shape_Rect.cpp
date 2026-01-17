#include <iostream>
using namespace std;

class Shape {
public:
    Shape() { cout << "1. Shape created." << endl; }
    
    // Virtual destructor is a best practice in inheritance
    virtual ~Shape() { 
        cout << "4. Shape destroyed (The Foundation is gone)." << endl; 
    }
};

class Rectangle : public Shape {
protected:
    int width, height;

public:
    Rectangle(int w, int h) : Shape() {
        width = w;
        height = h;
        cout << "2. Rectangle initialized." << endl;
    }

    ~Rectangle() {
        cout << "3. Rectangle destroyed (The Walls are gone)." << endl;
    }
};

int main() {
    {
        // Creating the object inside a block so it gets destroyed
        Rectangle myRect(5, 10);
    } 
    // myRect goes out of scope here and dies
    
    return 0;
}