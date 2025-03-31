#include <iostream>
using namespace std;

template <typename T>
class Box {
private:
    T value;
public:
    Box(T v) : value(v) {}  // Constructor to initialize the value
    T getValue() { return value; }  // Function to get the value
};

int main() {
    Box<int> intBox(5);  // Create an object of type Box with an int
    cout << "Box contains: " << intBox.getValue() << endl;

    Box<double> doubleBox(5.75);  // Create an object of type Box with a double
    cout << "Box contains: " << doubleBox.getValue() << endl;

    Box<string> stringBox("Hello, C++!");  // Create an object of type Box with a string
    cout << "Box contains: " << stringBox.getValue() << endl;

    return 0;
}
