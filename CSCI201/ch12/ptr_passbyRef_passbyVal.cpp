#include <iostream>
using namespace std;

// Illustrating the concept from image 3
// p is a reference to a pointer (can change the address itself)
// q is a pointer passed by value (can change what it points to, but not the address)
void pointerParameters(int* &p, double *q) {
    // Changing the value at the addresses (Works for both)
    *p = 777; 
    *q = 99.9;

    // Attempting to change the addresses themselves
    static int newInt = 888;
    static double newDouble = 11.1;

    p = &newInt;    // This WILL change the original pointer in main
    q = &newDouble; // This WILL NOT change the original pointer in main
}

int main() {
    int val1 = 10;
    double val2 = 20.5;

    int* myP = &val1;
    double* myQ = &val2;

    cout << "--- BEFORE FUNCTION ---" << endl;
    cout << "myP points to address: " << myP << " with value: " << *myP << endl;
    cout << "myQ points to address: " << myQ << " with value: " << *myQ << endl;

    pointerParameters(myP, myQ);

    cout << "\n--- AFTER FUNCTION ---" << endl;
    // myP's address changed because it was a reference parameter
    cout << "myP points to address: " << myP << " with value: " << *myP << endl;
    
    // myQ still points to the same address, though the value inside changed
    cout << "myQ points to address: " << myQ << " with value: " << *myQ << endl;

    return 0;
}