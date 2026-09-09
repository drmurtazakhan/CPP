// compile: g++ CopyConstructorTriggerObjPassByValue.cpp -o CopyConstructorTriggerObjPassByValue.exe
// run: ./CopyConstructorTriggerObjPassByValue.exe

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

        // Initialize array elements with sample values matching Figure 12-18
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

    // Member function accepting an object BY VALUE as a parameter (Situation 2)
    // The compiler automatically executes the default copy constructor to initialize 'other'
    void copyAndCompare(ptrMemberVarType other)
    {
        cout << "\n--- Inside Member Function (Object Passed by Value) ---" << endl;
        other.print("other (local copy inside function)");

        // Modifying data via 'other' inside the function
        other.setPElement(0, 99);
        cout << "\nInside member function after setting other.p[0] to 99:" << endl;
        other.print("other (local copy inside function)");

        cout << "\n--- Exiting Member Function ---" << endl;
        // When copyAndCompare ends, 'other' goes out of scope.
        // 'other''s destructor executes and calls 'delete [] p', freeing shared memory!
    }

    // Print function accepting the object name to clarify output
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

    cout << "--- Before Calling Member Function ---" << endl;
    objectOne.print("objectOne");

    // Situation 2: Passing objectOne by value to a member function of objectTwo
    // The default copy constructor automatically executes to make 'other' a shallow copy of 'objectOne'
    objectTwo.copyAndCompare(objectOne);

    cout << "\n--- Back in Main After Member Function Call ---" << endl;
    // objectOne.p now points to dynamic memory that was already deleted by 'other''s destructor
    objectOne.print("objectOne");

    cout << "\nNote: When main ends, both destructors will try to delete[] the same" << endl;
    cout << "memory space, resulting in undefined behavior" << endl;

    return 0;
}