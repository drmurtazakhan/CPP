// testTracker.cpp
// g++ DynamicTrackerImp.cpp testTracker.cpp -o testTracker.exe
// ./testTracker.exe

#include <iostream>
#include "DynamicTracker.h"
using namespace std;

int main() {
    // Create the object [cite: 13]
    DynamicTracker myTracker;

    // 1. Initialize heap memory
    myTracker.initialize();
    cout << "Memory initialized on the heap." << endl;

    // 2. Set the value to 100
    myTracker.setValue(100);

    // 3 & 4. Print current value and memory address
    cout << "Current Value: " << myTracker.getValue() << endl;
    cout << "Memory Address: " << myTracker.getAddress() << endl;

    // 5. Cleanup the memory
    myTracker.cleanup();
    cout << "Cleanup performed. Memory freed." << endl;

    // 6. Verify pointer is null by checking value (should be -1)
    cout << "Value after cleanup: " << myTracker.getValue() << endl;

    return 0;
}