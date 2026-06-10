// CopyConstructorTriggers2.cpp
// to compile: g++  CopyConstructorTriggers2.cpp -o CopyConstructorTriggers2.exe
// to run: ./CopyConstructorTriggers2.exe

#include <iostream>
using namespace std;

class TriggerDemo
{
public:
    int val;
    int *data; // Added pointer member to demonstrate shallow copy behavior

    // Parameterized Constructor
    TriggerDemo(int v, int d)
    {
        val = v;
        data = new int(d); // Allocate dynamic memory on the heap
        cout << "[Constructor] Object created with val = " << val << " and *data = " << *data << endl;
    }

    // No user-defined copy constructor is written here.
    // The compiler will provide its own default (shallow) copy constructor.

    // Destructor
    ~TriggerDemo()
    {
        // We leave delete out for this demo to prevent the program from crashing
        // due to double-freeing the same shared memory address.
    }

    // Helper function to easily print object states
    void display(const string &objName) const
    {
        cout << objName << " -> val: " << val
             << " (address of val: " << &val << ")\n";
        cout << objName << " -> *data: " << *data
             << " (address stored in data: " << data << ")\n\n";
    }
};

// Function where the object is passed by value (Triggers Copy Constructor)
void examineObject(TriggerDemo tempObj)
{
    cout << "--- Inside examineObject Function (Passed by Value) ---" << endl;
    tempObj.display("tempObj");
}

int main()
{
    cout << "--- Creating Original Object ---" << endl;
    TriggerDemo objectOne(10, 500);
    objectOne.display("objectOne");

    cout << "--- Trigger 1: Initializing an object during declaration ---" << endl;
    TriggerDemo objectTwo = objectOne;
    objectTwo.display("objectTwo");

    cout << "--- Trigger 2: Passing an object by value to a function ---" << endl;
    examineObject(objectOne);

    cout << "--- Demonstrating the Hazard of Shallow Copy ---" << endl;
    cout << "Modifying objectTwo's members..." << endl;
    objectTwo.val = 99;
    *objectTwo.data = 888; // This alters the shared heap memory!
    cout << endl;

    // Show the side-effect on the original object
    objectOne.display("objectOne");
    objectTwo.display("objectTwo");

    cout << "NOTICE: objectOne's 'val' stayed safe (10), but its '*data' changed to 888!" << endl;
    cout << "This proves 'val' was cleanly copied, but 'data' shares the same address." << endl;

    return 0;
}