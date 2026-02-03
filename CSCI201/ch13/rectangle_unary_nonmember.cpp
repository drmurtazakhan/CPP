// File name: rectangle_unary_nonmember.cpp
#include <iostream>
using namespace std;

class rectangleType {
private:
    double length;
    double width;

public:
    rectangleType(double l = 0, double w = 0) : length(l), width(w) {}

    // Rule 2a: Nonmember Friends with Return Type
    friend rectangleType operator++(rectangleType& rect);
    friend rectangleType operator--(rectangleType& rect);

    void print() const {
        cout << "[" << length << " x " << width << "]";
    }
};

// Implementation: Note NO rectangleType:: because it's a friend/nonmember
rectangleType operator++(rectangleType& rect) {
    rect.length++;
    rect.width++;
    return rect; // Return the object passed in
}

rectangleType operator--(rectangleType& rect) {
    rect.length--;
    rect.width--;
    return rect; // Return the object passed in
}

int main() {
    rectangleType rect1(10, 5);
    rectangleType rect2;

    cout << "Initial rect1: "; rect1.print(); cout << endl;

    rect2 = ++rect1; // operator++(rect1)

    cout << "After ++ calculation:" << endl;
    cout << "rect1: "; rect1.print(); cout << endl;
    cout << "rect2: "; rect2.print(); cout << endl;

    return 0;
}