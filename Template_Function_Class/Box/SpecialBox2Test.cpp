#include <iostream>
using namespace std;

// Generic Template Class
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
};

// Specialization for int type
template <>
class Box<int> {
    int value;
public:
    Box(int v) : value(v) {}
    int getValue() { return value * 2; }  // Example behavior for int
};

// Specialization for string type
template <>
class Box<string> {
    string value;
public:
    Box(string v) : value(v) {}
    string getValue() { return "Special String: " + value; }
};

int main() {
    Box<int> intBox(5);
    Box<string> strBox("Hello");

    cout << intBox.getValue() << endl;  // Outputs: 10
    cout << strBox.getValue() << endl;  // Outputs: Special String: Hello

    return 0;
}
