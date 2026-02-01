// File name: friend_op_demo.cpp
#include <iostream>
using namespace std;

class Box {
private:
    int width;
public:
    Box(int w = 0) : width(w) {}

    // RULE 2a: Left operand is an 'int', not a 'Box'. 
    // Must be a friend (nonmember).
    friend Box operator+(int leftValue, const Box& rightBox);

    void print() { cout << "Width: " << width << endl; }
};

// Definition: Notice no Box:: because it is a nonmember
Box operator+(int leftValue, const Box& rightBox) {
    return Box(leftValue + rightBox.width);
}

int main() {
    Box b1(5);
    Box b2 = 10 + b1; // 10 is on the far left!
    b2.print();       // Output: Width 15
    return 0;
}