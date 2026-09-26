// compile: g++ dynamic_array_return.cpp -o dynamic_array_return.exe
// run: ./dynamic_array_return.exe

#include <iostream>

using namespace std;

int *createRawArray(int size)
{
    int *arr = new int[size]; // Dynamic allocation on the heap
    for (int i = 0; i < size; i++)
    {
        arr[i] = (i + 1) * 10;
    }
    return arr; // Returns pointer to the first element
}

int main()
{
    int size = 5;
    int *myArray = createRawArray(size);

    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }

    delete[] myArray; // Free memory to avoid leaks
    return 0;
}