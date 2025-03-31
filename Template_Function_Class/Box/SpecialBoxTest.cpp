#include <iostream>
using namespace std;

// Generic Template Class
template <typename T>
class Box {
public:
    T value;
    Box(T v) : value(v) {}
    T getValue() { return value; }
};

// Template Specialization for string type
template <>
class Box<string> {
public:
    string value;
    Box(string v) : value(v) {}
    string getValue() { return "String Box: " + value; }
};

int main() {
    Box<int> intBox(100);
    cout << intBox.getValue() << endl;

    Box<string> strBox("Hello");
    cout << strBox.getValue() << endl;

    return 0;
}
