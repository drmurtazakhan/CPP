// fun_return_ptr.cpp
// to compile: g++ fun_return_ptr.cpp -o fun_return_ptr.exe
// to run: ./fun_return_ptr.exe
#include <iostream>
using namespace std;

// This function has a return type of 'int*'
// It creates a nameless integer in memory and returns its address
int *createDynamicInt(int value)
{
    // 1. Create a dynamic (nameless) variable in the heap
    int *numPtrLocal = new int;

    // 2. Put the value into that nameless variable
    *numPtrLocal = value;

    // 3. Return the address so main() can find it
    return numPtrLocal;
}

int main()
{
    // Create a local variable in main
    int num = 500;
    cout << "The value of num " << num << endl;
    cout << "The address of num is: " << &num << endl;

    // Declare a pointer to receive the address from the function
    int *numPtrMain;

    // Call the function and store the returned address
    numPtrMain = createDynamicInt(num);

    // Use the returned pointer to see the value
    cout << "The value in the returned pointer is: " << *numPtrMain << endl;
    cout << "The address returned by the function is: " << numPtrMain << endl;

    // IMPORTANT: Since the function used 'new', we must 'delete' it here
    delete numPtrMain;

    return 0;
}