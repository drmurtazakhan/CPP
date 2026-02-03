// File name: rectangle_unary_nonmember_postfix.cpp
#include <iostream>
using namespace std;

class rectangleType {
private:
    double length;
    double width;

public:
    rectangleType(double l = 0, double w = 0) : length(l), width(w) {}

    // 1. Added (int) as the SECOND parameter for Postfix
    friend rectangleType operator++(rectangleType& rect, int);
    friend rectangleType operator--(rectangleType& rect, int);

    void print() const {
        cout << "[" << length << " x " << width << "]";
    }
};

// 2. Implementation: rect is the object, the 'int' is the dummy tag
rectangleType operator++(rectangleType& rect, int) {
    rectangleType temp = rect; // 3. Save the OLD state of the parameter

    rect.length++; 
    rect.width++;  
    
    return temp; // 4. Return the OLD state
}

rectangleType operator--(rectangleType& rect, int) {
    rectangleType temp = rect; // 3. Save the OLD state

    rect.length--; 
    rect.width--;  
    
    return temp; // 4. Return the OLD state
}

int main() {
    rectangleType rect1(10, 5);
    rectangleType rect2;

    cout << "Initial rect1: "; rect1.print(); cout << endl;

    // 5. The compiler calls operator++(rect1, 0)
    rect2 = rect1++; 

    cout << "After rect1++ calculation:" << endl;
    cout << "rect1 (changed): "; rect1.print(); cout << endl; // [11 x 6]
    cout << "rect2 (got old): "; rect2.print(); cout << endl; // [10 x 5]

    return 0;
}