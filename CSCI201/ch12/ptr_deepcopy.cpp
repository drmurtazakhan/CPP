// ptr_deepcopy.cpp
// Compile: g++ ptr_deepcopy.cpp -o ptr_deepcopy.exe
// Run: ./ptr_deepcopy.exe
#include <iostream>
using namespace std;

void printArray(const int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int *first;
    int *second;

    // 1. Create original array initialized with the given values
    first = new int[10]{10, 36, 89, 29, 47, 64, 28, 92, 37, 73};

    // 2. Perform Deep Copy
    // Create a NEW independent array for 'second'
    second = new int[10];
    for (int j = 0; j < 10; j++)
    {
        second[j] = first[j]; // Copy values one by one
    }

    cout << "First array:  ";
    printArray(first, 10);
    cout << "Second array: ";
    printArray(second, 10);

    // 3. Demonstrate independence
    second[0] = 99;
    cout << "\nAfter modifying second[0] to 99:" << endl;
    cout << "First array:  ";
    printArray(first, 10); // Remains unchanged
    cout << "Second array: ";
    printArray(second, 10); // Only this changes

    // Cleanup: Must delete BOTH because they are separate arrays
    delete[] first;
    delete[] second;

    return 0;
}