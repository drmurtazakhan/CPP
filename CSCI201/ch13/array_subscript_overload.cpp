// File name: array_subscript_overload.cpp
#include <iostream>
using namespace std;

class listType {
private:
    int list[4]; // A simple array inside our class

public:
    listType() {
        // Initialize with some default values
        for (int i = 0; i < 4; i++) list[i] = 0;
    }

    // Rule 1: MUST be a member function
    // Returns a reference (int&) so we can modify the value
    int& operator[](int index);
};

// Implementation
int& listType::operator[](int index) {
    // Simple bounds checking (Standard practice in Chapter 13)
    if (index < 0 || index >= 4) {
        cerr << "Index out of bounds!" << endl;
        return list[0]; // Return first element as a safety
    }

    return list[index]; // Return the actual element at that position
}

int main() {
    listType myData;

    // Writing to the object like an array
    myData[0] = 10;
    myData[1] = 20;
    myData[2] = 30;
    myData[3] = 40;

    cout << "Values in myData object:" << endl;
    for (int i = 0; i < 4; i++) {
        // Reading from the object like an array
        cout << "Index " << i << ": " << myData[i] << endl;
    }

    return 0;
}