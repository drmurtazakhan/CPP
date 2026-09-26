// compile: g++ array_return.cpp -o array_return.exe
// run: ./array_return.exe
#include <iostream>
#include <array>

using namespace std;

array<int, 5> createArray()
{
    array<int, 5> arr = {10, 20, 30, 40, 50};
    return arr; // Returns a copy of the array
}

int main()
{
    array<int, 5> myArray = createArray();
    for (int val : myArray)
    {
        cout << val << " ";
    }
    return 0;
}