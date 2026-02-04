// File name: array_list_template.cpp
#include <iostream>
#include <string>
using namespace std;

template <class elemType>
class arrayListType {
private:
    elemType *list;    // Pointer to hold the dynamic array
    int length;        // Current number of elements
    int maxSize;       // Maximum capacity of the array

public:
    // Constructor: Creates an array of a specific size
    arrayListType(int size = 100) {
        maxSize = size;
        length = 0;
        list = new elemType[maxSize]; // Array of elemType
    }

    // Destructor: Clean up memory
    ~arrayListType() {
        delete [] list;
    }

    // Method to add an item
    void insert(const elemType& insertItem) {
        if (length < maxSize) {
            list[length] = insertItem;
            length++;
        } else {
            cout << "List is full!" << endl;
        }
    }

    // Method to print the list
    void print() const {
        for (int i = 0; i < length; i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // 1. A list of Integers
    arrayListType<int> intList(5);
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);
    cout << "Integer List: ";
    intList.print();

    // 2. A list of Strings
    // The same class now handles string data!
    arrayListType<string> stringList(5);
    stringList.insert("C++");
    stringList.insert("Templates");
    stringList.insert("Logic");
    cout << "String List: ";
    stringList.print();

    return 0;
}