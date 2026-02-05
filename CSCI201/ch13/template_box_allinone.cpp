// File name: template_box_allinone.cpp
// Case 1: All code in a single file
#include <iostream>
using namespace std;

// Class and functions defined right here
template <class T>
class Box {
    T data;
public:
    Box(T d) : data(d) {}
    void show() { cout << data << endl; }
};

int main() {
    Box<int> b(10);
    b.show();
    return 0;
}