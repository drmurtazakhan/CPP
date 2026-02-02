// File name: rectangle_stream_ops.cpp
#include <iostream>
using namespace std;

class rectangleType {
private:
    double length;
    double width;

public:
    rectangleType(double l = 0, double w = 0) : length(l), width(w) {}

    // Rule 2a: Nonmember Friends
    // We pass the stream (cout/cin) by reference as the first parameter
    friend ostream& operator<<(ostream& os, const rectangleType& rect);
    friend istream& operator>>(istream& is, rectangleType& rect);
};

// Overloading << (Insertion/Output)
// It returns ostream& so we can chain multiple << operators
ostream& operator<<(ostream& os, const rectangleType& rect) {
    os << "Length: " << rect.length << ", Width: " << rect.width;
    return os;
}

// Overloading >> (Extraction/Input)
istream& operator>>(istream& is, rectangleType& rect) {
    // We assume the user enters: length width
    is >> rect.length >> rect.width;
    return is;
}

int main() {
    rectangleType myRectangle;

    cout << "Enter the length and width of the rectangle separated by a space: ";
    
    // The compiler translates this to: operator>>(cin, myRectangle)
    cin >> myRectangle;

    cout << "------------------------------------" << endl;
    cout << "You entered the following rectangle:" << endl;
    
    // The compiler translates this to: operator<<(cout, myRectangle)
    cout << myRectangle << endl;

    return 0;
}