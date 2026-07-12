// File name: char_array_init2.cpp
// compile: g++ char_array_init2.cpp -o char_array_init2.exe
// run: ./char_array_init2.exe

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

    // Print name1 character by character
    cout << "Name 1 characters:" << endl;
    int i = 0;
    // Loop until the null terminator is encountered
    while (name1[i] != '\0')
    {
        cout << name1[i] << endl;
        i++;
    }

    // Print name2 character by character
    cout << "Name 2 characters:" << endl;
    int j = 0;
    // Loop until the null terminator is encountered
    while (name2[j] != '\0')
    {
        cout << name2[j] << endl;
        j++;
    }

    return 0;
}