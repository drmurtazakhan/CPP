// compile: g++ CopyConstructorDeep.cpp -o CopyConstructorDeep.exe
// run: ./CopyConstructorDeep.exe

// File: ptr_copy_constructor_deep_member.cpp
// Title: Deep Copy Demonstration with Member Function
// To compile: g++ ptr_copy_constructor_deep_member.cpp -o ptr_copy_constructor_deep_member.exe
// To run: ./ptr_copy_constructor_deep_member.exe

#include <iostream>
#include <string>
using namespace std;

class ptrMemberVarType
{
public:
    // Default / Parameterized Constructor
    ptrMemberVarType(int valX = 8, int length = 50)
    {
        x = valX;
        lenP = length;
        p = new int[lenP]; // Allocate dynamic memory

        // Sample initial values
        p[0] = 5;
        p[1] = 36;
        p[2] = 24;
        p[3] = 15;
    }

    // Custom Copy Constructor (Performs Deep Copy)
    ptrMemberVarType(const ptrMemberVarType &otherObject)
    {
        x = otherObject.x;
        lenP = otherObject.lenP;

        // 1. Allocate a brand-new dynamic array for this object
        p = new int[lenP];

        // 2. Copy elements individually from source object
        for (int i = 0; i < lenP; i++)
        {
            p[i] = otherObject.p[i];
        }
    }

    // Destructor
    ~ptrMemberVarType()
    {
        delete[] p; // Frees only the memory owned by this specific object
    }

    // Member function called by objectTwo to modify its own member variables
    void copyAndCompare()
    {
        cout << "\n--- Inside copyAndCompare Member Function ---" << endl;

        // Modify objectTwo's x, lenP, and first array element
        x = 99;
        lenP = 100;
        p[0] = 77;

        print("objectTwo (inside function after modifications)");
        cout << "--- Exiting Member Function ---" << endl;
    }

    // Print helper function
    void print(string objName) const
    {
        cout << objName << ":" << endl;
        cout << "  x = " << x << ", lenP = " << lenP << endl;
        cout << "  Pointer p points to address: " << p << endl;
        cout << "  First four values in p: " << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << endl;
    }

private:
    int x;
    int lenP;
    int *p;
};

int main()
{
    // 1. Create original objectOne
    ptrMemberVarType objectOne(8, 50);

    // 2. Create objectTwo using the Copy Constructor (Deep Copy)
    ptrMemberVarType objectTwo(objectOne);

    cout << "--- Initial State in Main ---" << endl;
    objectOne.print("objectOne");
    cout << endl;
    objectTwo.print("objectTwo");

    // 3. Call copyAndCompare on objectTwo
    objectTwo.copyAndCompare();

    cout << "\n--- Back in Main After Function Call ---" << endl;
    // Verify objectOne remains completely unchanged
    objectOne.print("objectOne");
    cout << endl;
    // Verify objectTwo retains its modified values independently
    objectTwo.print("objectTwo");

    return 0;
}