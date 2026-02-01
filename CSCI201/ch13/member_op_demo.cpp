// File name: member_op_demo.cpp
#include <iostream>
using namespace std;

class Box {
private:
    int width;

public:
    // Constructor
    Box(int w = 0) : width(w) {}

    // RULE 2b: The left operand is a Box object, so this can be a member.
    // 'this->width' is the left side, 'addWidth' is the right side.
    Box operator+(int addWidth) const {
        return Box(this->width + addWidth);
    }

    // Function to display info
    void print() const {
        cout << "Box Width: " << width << endl;
    }
};

int main() {
    // 1. Create a Box object
    Box b1(20);
    
    cout << "Original Box:" << endl;
    b1.print();
    cout << "-------------------" << endl;

    // 2. Use the member operator+ 
    // This works because 'b1' (a Box) is on the far left.
    Box b2 = b1 + 15; 

    cout << "New Box (after b1 + 15):" << endl;
    b2.print(); // Should show 35

    return 0;
}