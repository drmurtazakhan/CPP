// File name: overload_binary_operator.cpp
#include <iostream>
using namespace std;

class rectangleType {
private:
    double length;
    double width;

public:
    rectangleType(double l = 0, double w = 0) : length(l), width(w) {}

    // Overloading the binary operator '#' (using + as the example)
    // Rule 2b: As a member function, it only needs ONE parameter
    rectangleType operator+(const rectangleType& yourRectangle) const {
        rectangleType temp;

        // 'length' refers to the object on the LEFT (myRectangle)
        // 'yourRectangle.length' refers to the object on the RIGHT
        temp.length = this->length + yourRectangle.length;
        temp.width = this->width + yourRectangle.width;

        return temp;
    }

    void print() const {
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};

int main() {
    rectangleType myRectangle(12, 8);
    rectangleType yourRectangle(5, 4);
    rectangleType result;

    // The expression: myRectangle # yourRectangle
    // Compiler translates this to: myRectangle.operator+(yourRectangle)
    result = myRectangle + yourRectangle;

    cout << "myRectangle: "; myRectangle.print();
    cout << "yourRectangle: "; yourRectangle.print();
    cout << "Result: "; result.print();

    return 0;
}