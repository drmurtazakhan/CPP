// File Name: enume_colors.cpp
// Compile: g++ enume_colors.cpp -o enume_colors.exe
// Run: ./enume_colors.exe

// This program demonstrates the use of enumeration (enum) in C++.

#include <iostream>
using namespace std;

// Define a new enumeration data type called colors.
// By default, the first enumerator starts with 0.
enum colors
{
    BROWN, // 0
    BLUE,  // 1
    RED,   // 2
    GREEN, // 3
    YELLOW // 4
};

int main()
{
    // Declare a variable of type colors.
    colors favoriteColor;

    // Assign one of the enumerator values.
    favoriteColor = GREEN;

    // Display the integer value of the enumerator.
    cout << "The integer value of GREEN is: "
         << favoriteColor << endl;

    // Demonstrate the ordering of enumeration values.
    if (RED < GREEN)
    {
        cout << "RED comes before GREEN in the enumeration." << endl;
    }

    // Another example
    if (BROWN < YELLOW)
    {
        cout << "BROWN comes before YELLOW." << endl;
    }

    return 0;
}