// File name: subscript_modify_vs_read.cpp
#include <iostream>
using namespace std;

class listType {
private:
    int list[4];

public:
    listType() {
        for (int i = 0; i < 4; i++) list[i] = i + 1; // Starts as 1, 2, 3, 4
    }

    // 1. Nonconstant version: Used to double the values
    int& operator[](int index);

    // 2. Constant version: Used for printing/reading
    const int& operator[](int index) const;
};

// Implementation: Returns a reference so we can modify the original data
int& listType::operator[](int index) {
    return list[index];
}

// Implementation: Returns a const reference (Read-only)
const int& listType::operator[](int index) const {
    return list[index];
}

// This function takes a CONST object, so it triggers the CONST operator[]
void printList(const listType& temp) {
    cout << "Current List: ";
    for (int i = 0; i < 4; i++) {
        cout << temp[i] << " "; // Triggers the 'const' version
    }
    cout << endl;
}

int main() {
    listType myData;

    cout << "--- Initial State ---" << endl;
    printList(myData);

    cout << "\n--- Doubling values using Non-const operator[] ---" << endl;
    for (int i = 0; i < 4; i++) {
        myData[i] = myData[i] * 2; // Triggers the 'non-const' version to write
    }

    cout << "--- After Doubling ---" << endl;
    printList(myData);

    return 0;
}