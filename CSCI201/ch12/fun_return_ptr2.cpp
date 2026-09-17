// fun_return_ptr.cpp
// to compile: g++ fun_return_ptr2.cpp -o fun_return_ptr2.exe
// to run: ./fun_return_ptr2.exe

#include <iostream>
using namespace std;

// The return type is 'int*'.
// This means the function returns the memory address of an int.
int *ptrReturnFunction()
{
    // Dynamically allocate an int and store 500 in it.
    int *numPtrLocal = new int(500);

    cout << "The value in function: " << *numPtrLocal << endl;
    cout << "The address of the int in function: "
         << numPtrLocal << endl;

    // Return the address of the dynamically allocated int.
    return numPtrLocal;
}

int main()
{
    // Declare a pointer to receive the address returned by the function.
    int *numPtrMain;

    // The function returns an address.
    numPtrMain = ptrReturnFunction();

    // Use the returned pointer to access the value.
    cout << "The value in the returned pointer: "
         << *numPtrMain << endl;

    // The pointer contains the same address returned by the function.
    cout << "The address returned by the function: "
         << numPtrMain << endl;

    // Release the dynamically allocated memory.
    delete numPtrMain;

    return 0;
}
