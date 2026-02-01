// File name: pointer_to_member_demo.cpp
#include <iostream>
using namespace std;

class SimpleBox {
public:
    int length;
    int width;
};

int main() {
    SimpleBox myBox;
    myBox.length = 10;

    // 1. Create a "pointer to a member" of type 'int' inside 'SimpleBox'
    // This doesn't point to myBox.length yet; it just points to the 'idea' of length.
    int SimpleBox::*ptrToMember = &SimpleBox::length;

    // 2. Use the .* operator to access that member on a specific object
    cout << "Length using .* operator: " << myBox.*ptrToMember << endl;

    return 0;
}