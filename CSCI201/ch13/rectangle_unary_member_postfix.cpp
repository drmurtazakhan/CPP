// File name: rectangle_unary_member_postfix.cpp
#include <iostream>
using namespace std;

class rectangleType {
private:
    double length;
    double width;

public:
    rectangleType(double l = 0, double w = 0) : length(l), width(w) {}

    // 1. Added (int) to make it Post-increment
    rectangleType operator++(int); 
    rectangleType operator--(int); 

    void print() const {
        cout << "[" << length << " x " << width << "]";
    }
};

// 1. Added (int) dummy parameter
rectangleType rectangleType::operator++(int) {
    rectangleType temp = *this; // 2. Save the OLD state

    length++; 
    width++;  
    
    return temp; // 3. Return the OLD state
}

// 1. Added (int) dummy parameter
rectangleType rectangleType::operator--(int) {
    rectangleType temp = *this; // 2. Save the OLD state

    length--; 
    width--;  
    
    return temp; // 3. Return the OLD state
}

int main() {
    rectangleType rect1(10, 5);
    rectangleType rect2;

    cout << "Initial rect1: "; rect1.print(); cout << endl;

    // 4. Using Post-increment (rect1++)
    rect2 = rect1++; 

    cout << "After rect1++ calculation:" << endl;
    cout << "rect1 (changed): "; rect1.print(); cout << endl; // Shows [11 x 6]
    cout << "rect2 (got old): "; rect2.print(); cout << endl; // Shows [10 x 5]

     return 0;
}