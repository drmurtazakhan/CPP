// File name: char_array_init.cpp
// compile: g++ char_array_init.cpp -o char_array_init.exe
// run: ./char_array_init.exe

#include <iostream>

using namespace std;

int main()
{
    // Method 1: Initializing by listing each character.
    // We must manually include the null terminator '\0'.
    char name1[16] = {'J', 'o', 'h', 'n', '\0'};

    // Method 2: Initializing using C-string notation.
    // The compiler automatically adds the null terminator for us.
    char name2[16] = "John";

    // Both methods result in identical storage
    cout << "Name 1: " << name1 << endl;
    cout << "Name 2: " << name2 << endl;

    return 0;
}