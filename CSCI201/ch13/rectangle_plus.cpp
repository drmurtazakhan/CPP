// File name: rectangle_width_height.cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    int width, height; // Using width and height as requested
public:
    // Constructor with default parameters
    Rectangle(int w = 0, int h = 0) : width(w), height(h) {}

    // Overloading the + operator as a member function
    // This is a value-returning function that returns a NEW object 
    Rectangle operator+(const Rectangle& otherRect) const {
        Rectangle temp;
        // Accessing the private members of both rectangles 
        temp.width = this->width + otherRect.width;
        temp.height = this->height + otherRect.height;
        return temp;
    }

    void print() const {
        cout << "Width = " << width << "; Height = " << height << endl;
    }
};

int main() {
    Rectangle rect1(12, 8);
    Rectangle rect2(5, 4);
    
    // The + operator now uses our custom logic 
    Rectangle rect3 = rect1 + rect2; 

    cout << "Resulting Rectangle: ";
    rect3.print(); // Output: Width = 17; Height = 12

    return 0;
}