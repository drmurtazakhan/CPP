// File name: rectangle_nonmember_op.cpp
#include <iostream>
using namespace std;

class rectangleType {
private:
    double length;
    double width;

public:
    rectangleType(double l = 0, double w = 0) : length(l), width(w) {}

    // DECLARATION: Rule 2a - Nonmember Friend
    // We must list BOTH operands as parameters.
    friend rectangleType operator+(const rectangleType& first, const rectangleType& second);
    friend bool operator==(const rectangleType& first, const rectangleType& second);

    void print() const {
        cout << "[" << length << " x " << width << "]";
    }
};

// DEFINITION: Notice there is NO rectangleType:: because it's a nonmember!
rectangleType operator+(const rectangleType& first, const rectangleType& second) {
    // We access private members using the parameter names (first and second)
    return rectangleType(first.length + second.length, 
                         first.width + second.width);
}

bool operator==(const rectangleType& first, const rectangleType& second) {
    return (first.length == second.length && 
            first.width == second.width);
}

int main() {
rectangleType myRectangle(12.0, 8.0);
    rectangleType yourRectangle(5.0, 4.0);

    // Print the inputs
    cout << "myRectangle: "; myRectangle.print(); cout << endl;
    cout << "yourRectangle: "; yourRectangle.print(); cout << endl;
    cout << "------------------------------------" << endl;

    // The + operation: operator+(myRectangle, yourRectangle)
    rectangleType result = myRectangle + yourRectangle;
    cout << "Result of + : "; result.print(); cout << endl;

    // The == operation: operator==(myRectangle, yourRectangle)
    cout << "Testing ==  : ";
    if (myRectangle == yourRectangle) {
        cout << "The rectangles are equal!" << endl;
    } else {
        cout << "The rectangles are NOT equal." << endl;
    }

    return 0;
}