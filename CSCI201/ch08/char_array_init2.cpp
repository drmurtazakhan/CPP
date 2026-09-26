// File name: char_array_init2.cpp
// compile: g++ char_array_init2.cpp -o char_array_init2.exe
// run: ./char_array_init2.exe

#include <iostream>

using namespace std;

int main()
{
    // =========================================================================
    // DIFFERENCE EXPLANATION:
    //
    // Option A: char name1[16] = {'J', 'o', 'h', 'n', '\0'};
    // - You explicitly supply the null terminator '\0' at index 4.
    // - Indices 5 to 15 are still unsupplied, so C++ auto-fills them with '\0'.
    //
    // Option B: char name1[16] = {'J', 'o', 'h', 'n'};
    // - You do NOT explicitly write '\0'.
    // - However, C++ partial initialization rules dictate that when an array is
    //   partially initialized, ALL remaining unsupplied elements (indices 4 to 15)
    //   are automatically filled with 0 (which is the '\0' character).
    //
    // RESULT: Both declarations produce the EXACT same memory layout!
    // =========================================================================

    // Method 1: Initializing by listing characters (partial initialization)
    // Remaining 12 elements (indices 4..15) automatically become '\0'
    char name1[16] = {'J', 'o', 'h', 'n'};

    // Method 2: Initializing using C-string notation.
    // The compiler automatically appends '\0' after 'n', and zeroes the rest of the array.
    char name2[16] = "John";

    // Print name1 character by character
    cout << "Name 1 characters:" << endl;
    int i = 0;
    // Loop until the null terminator is encountered (stops at index 4)
    while (name1[i] != '\0')
    {
        cout << name1[i] << endl;
        i++;
    }

    // Print name2 character by character
    cout << "Name 2 characters:" << endl;
    int j = 0;
    // Loop until the null terminator is encountered (stops at index 4)
    while (name2[j] != '\0')
    {
        cout << name2[j] << endl;
        j++;
    }

    return 0;
}