#include <iostream>
using namespace std;

// This function has a return type of 'int*'
// It creates a nameless integer in memory and returns its address
int* createDynamicInt(int value) {
    // 1. Create a dynamic (nameless) variable in the heap
    int* ptr = new int; 
    
    // 2. Put the value into that nameless variable
    *ptr = value; 
    
    // 3. Return the address so main() can find it
    return ptr; 
}

int main() {
    // Declare a pointer to receive the address from the function
    int* myNumber;

    // Call the function and store the returned address
    myNumber = createDynamicInt(500);

    // Use the returned pointer to see the value
    cout << "The value in the returned pointer is: " << *myNumber << endl;
    cout << "The address returned by the function is: " << myNumber << endl;

    // IMPORTANT: Since the function used 'new', we must 'delete' it here
    delete myNumber;

    return 0;
}