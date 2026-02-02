// File name: rectangle_assignment_op.cpp
#include <iostream>
using namespace std;

class rectangleType {
private:
    double length;
    double width;

public:
    rectangleType(double l = 0, double w = 0) : length(l), width(w) {}

    // Rule 1: MUST be a member function
    // Returns a reference to the object (rectangleType&) to allow chaining like a = b = c;
    const rectangleType& operator=(const rectangleType& otherRect) {
        
        // 1. Avoid self-assignment (e.g., rect1 = rect1)
        if (this != &otherRect) {
            // 2. Copy the data
            length = otherRect.length;
            width = otherRect.width;
        }

        // 3. Return the object itself
        return *this; 
    }

    void print() const {
        cout << "[" << length << " x " << width << "]";
    }
};

int main() {
    rectangleType rect1(15.0, 7.0);
    rectangleType rect2; // Starts at 0, 0

    cout << "Before assignment:" << endl;
    cout << "rect1: "; rect1.print(); cout << endl;
    cout << "rect2: "; rect2.print(); cout << endl;

    // The assignment: rect2.operator=(rect1)
    rect2 = rect1;

    cout << "\nAfter rect2 = rect1:" << endl;
    cout << "rect2: "; rect2.print(); cout << endl;

    return 0;
}