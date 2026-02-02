// File name: rectangle_multi_op.cpp
#include <iostream>
using namespace std;

class rectangleType {
private:
    double length;
    double width;

public:
    rectangleType(double l = 0, double w = 0) : length(l), width(w) {}

    // Rule 2b: Member function for +
    rectangleType operator+(const rectangleType& yourRectangle) const {
        return rectangleType(length + yourRectangle.length, 
                             width + yourRectangle.width);
    }

    // Rule 2b: Member function for ==
    bool operator==(const rectangleType& yourRectangle) const {
        return (length == yourRectangle.length && 
                width == yourRectangle.width);
    }

    void print() const {
        cout << "[" << length << " x " << width << "]";
    }
};

int main() {
    // 1. Create rect1 and rect2 with the same values
    rectangleType rect1(10.0, 5.0);
    rectangleType rect2(10.0, 5.0);

    // 2. Create rect3 using the + operator
    // This will result in (10+10) x (5+5) = [20.0 x 10.0]
    rectangleType rect3 = rect1 + rect2; 

    cout << "rect1: "; rect1.print(); cout << endl;
    cout << "rect2: "; rect2.print(); cout << endl;
    cout << "rect3 (rect1 + rect2): "; rect3.print(); cout << endl;
    cout << "------------------------------------" << endl;

    // 3. Test equality between rect1 and rect2 (Should be TRUE/Equal)
    cout << "Testing rect1 == rect2: ";
    if (rect1 == rect2) 
        cout << "Equal" << endl;
    else 
        cout << "Not Equal" << endl;

    // 4. Test equality between rect1 and rect3 (Should be FALSE/Not Equal)
    cout << "Testing rect1 == rect3: ";
    if (rect1 == rect3) 
        cout << "Equal" << endl;
    else 
        cout << "Not Equal" << endl;

    return 0;
}