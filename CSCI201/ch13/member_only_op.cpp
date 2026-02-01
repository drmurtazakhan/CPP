// File name: member_only_op.cpp
#include <iostream>
using namespace std;

class Box {
private:
    int width;

public:
    // Constructor to initialize width
    Box(int w = 0) : width(w) {}

    // RULE 1: The '=' operator MUST be a member function.
    // It takes the 'other' box (right side) and copies its data to 'this' box (left side).
    void operator=(const Box& other) {
        cout << "...Member Assignment Operator Called..." << endl;
        this->width = other.width;
    }

    // Function to display the width
    void display() const {
        cout << "Box width: " << width << endl;
    }
};

int main() {
    // Create two box objects
    Box boxA(50);
    Box boxB(0);

    cout << "Before Assignment:" << endl;
    cout << "boxA: "; boxA.display();
    cout << "boxB: "; boxB.display();
    cout << "-------------------" << endl;

    // Use the overloaded = operator
    // boxB is the calling object (this), boxA is the parameter (other)
    boxB = boxA; 

    cout << "After Assignment (boxB = boxA):" << endl;
    cout << "boxA: "; boxA.display();
    cout << "boxB: "; boxB.display();

    return 0;
}