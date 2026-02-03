// File name: rectangle_unary_member.cpp
#include <iostream>
using namespace std;

class rectangleType {
private:
    double length;
    double width;

public:
    rectangleType(double l = 0, double w = 0) : length(l), width(w) {}

    // The textbook style: Returns the updated object itself
    rectangleType operator++();
    rectangleType operator--();

    void print() const {
        cout << "[" << length << " x " << width << "]";
    }
};

// Implementation using the Scope Resolution Operator ::
rectangleType rectangleType::operator++() {
    length++; // Increment length
    width++;  // Increment width    
    return *this; // Return the caller object
}

rectangleType rectangleType::operator--() {
    length--; // Decrement length
    width--;  // Decrement width
    
    return *this; // Return the object that was just changed
}

int main() {
    rectangleType rect1(10, 5);
    rectangleType rect2;

    cout << "Initial rect1: "; rect1.print(); cout << endl;

    // Because we return rectangleType, we can assign the result!
    rect2 = ++rect1; 

    cout << "After ++ calculation:" << endl;
    cout << "rect1 is now: "; rect1.print(); cout << endl;
    cout << "rect2 is now: "; rect2.print(); cout << endl;

    --rect1;
    cout << "After -- rect1: "; rect1.print(); cout << endl;

    return 0;
}