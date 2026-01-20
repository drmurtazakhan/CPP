#include <iostream>
using namespace std;

int main() {
    // 1. Declare a pointer variable of type int
    int *p;

    /* 2. Create a DYNAMIC ARRAY
       This allocates 10 contiguous memory locations in the heap.
       The address of the first location is stored in p. */
    p = new int[10];

    // 3. Accessing memory using the DEREFERENCE operator (*)
    *p = 25; // Stores 25 in the first memory location (index 0)
    cout << "Value at p[0] using *p: " << *p << endl;

    // 4. Using POINTER ARITHMETIC (p++)
    p++;      // Moves the pointer to the next array component (index 1)
    *p = 35;  // Stores 35 into the second memory location
    cout << "Value at p[1] after p++: " << *p << endl;

    /* 5. IMPORTANT: Return p to the start
       Since we moved p, we must move it back to the beginning 
       to use array notation correctly. */
    p--; 

    // 6. Accessing memory using ARRAY NOTATION
    // This is often easier and safer than p++
    p[0] = 25; 
    p[1] = 35;
    cout << "Value at p[1] using array notation: " << p[1] << endl;

    // 7. Using a FOR loop to initialize the whole array to 0
    for (int j = 0; j < 10; j++) {
        p[j] = 0;
    }
    cout << "Array successfully initialized to 0." << endl;

    // 8. Clean up
    // Always use delete[] when you used new[]
    delete[] p;

    return 0;
}