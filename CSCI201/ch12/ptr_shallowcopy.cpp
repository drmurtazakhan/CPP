// compile: g++ ptr_shallowcopy.cpp -o ptr_shallowcopy.exe
// run: ./ptr_shallowcopy.exe

#include <iostream>
using namespace std;

// Helper function to print the array using const int*
void printArray(const int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int *first;
    int *second;

    // 1. Create original array initialized with image values
    first = new int[10]{10, 36, 89, 29, 47, 64, 28, 92, 37, 73};

    // 2. Perform Shallow Copy
    // Both pointers now point to the same memory address
    second = first;

    cout << "First array:  ";
    printArray(first, 10);
    cout << "Second array: ";
    printArray(second, 10);

    // 3. Demonstrate shared memory
    second[0] = 99;
    cout << "\nAfter modifying second[0] to 99:" << endl;
    cout << "First array:  ";
    printArray(first, 10); // Also shows 99!
    cout << "Second array: ";
    printArray(second, 10);

    // Cleanup: Only delete one, because both point to the same thing
    delete[] second;
    // first is now a 'dangling pointer' and should not be used

    return 0;
}