// compile: g++ -std=c++17 Fig12_16.cpp -o Fig12_16.exe
// run: ./Fig12_16.exe

#include <iostream>
#include <string>
using namespace std;

class ptrMemberVarType
{
public:
    // Constructor to initialize member variables and dynamically allocate array p
    ptrMemberVarType(int valX = 8, int length = 50)
    {
        x = valX;
        lenP = length;
        p = new int[lenP]; // Allocate dynamic memory

        // Initialize array elements with sample values matching the diagram
        p[0] = 5;
        p[1] = 36;
        p[2] = 24;
        p[3] = 15;
    }

    // Destructor to deallocate memory created by pointer p
    ~ptrMemberVarType()
    {
        delete[] p; // Deallocates dynamic memory when an object goes out of scope
    }

    // Updated print function accepting the object name to clarify output
    void print(string objName) const
    {
        cout << objName << ":" << endl;
        cout << "  x = " << x << ", lenP = " << lenP << endl;
        cout << "  Pointer p of " << objName << " points to address: " << p << endl;
        cout << "  First four values in p: " << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << endl;
    }

    // Function to modify an element in the dynamic array
    void setPElement(int index, int value)
    {
        p[index] = value;
    }

private:
    int x;    // Member variable
    int lenP; // Length of dynamic array
    int *p;   // Pointer member variable
};

int main()
{
    // Create objectOne with values x = 8, lenP = 50
    ptrMemberVarType objectOne(8, 50);

    // Create objectTwo
    ptrMemberVarType objectTwo;

    // Default member-wise assignment results in a Shallow Copy
    // Both objectTwo.p and objectOne.p now store the same memory address
    objectTwo = objectOne;

    cout << "--- Initial State ---" << endl;
    objectOne.print("objectOne");
    cout << endl;
    objectTwo.print("objectTwo");

    // Modifying data via objectTwo affects objectOne because they share memory
    objectTwo.setPElement(0, 99);

    cout << "\n--- After modifying objectTwo.p[0] to 99 ---" << endl;
    objectOne.print("objectOne"); // Shows 99 because objectOne and objectTwo share the array
    cout << endl;
    objectTwo.print("objectTwo");

    cout << "\nNote: When main ends, both destructors will try to delete[] the same" << endl;
    cout << "memory space, resulting in undefined behavior" << endl;

    return 0;
}