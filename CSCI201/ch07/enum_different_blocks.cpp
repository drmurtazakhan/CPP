// This program will compile successfully because RED and GREEN
// are declared in two different blocks.
//
// The first enumeration is inside the first block.
// The second enumeration is inside the second block.
//
// Compile: g++ enum_different_blocks.cpp -o enum_different_blocks.exe
// Run: ./enum_different_blocks.exe

#include <iostream>
using namespace std;

int main()
{
    {
        // First enumeration is declared inside the first block.
        enum Color
        {
            RED,
            GREEN,
            BLUE
        };

        // Print the values of the Color enumeration.
        cout << "Color enumeration:" << endl;
        cout << "RED = " << RED << endl;
        cout << "GREEN = " << GREEN << endl;
        cout << "BLUE = " << BLUE << endl;
    } // RED, GREEN, and BLUE go out of scope here.

    {
        // Second enumeration is declared inside a different block.
        // RED and GREEN can be used again because the first block has ended.
        enum TrafficLight
        {
            RED,
            YELLOW,
            GREEN
        };

        // Print the values of the TrafficLight enumeration.
        cout << "\nTrafficLight enumeration:" << endl;
        cout << "RED = " << RED << endl;
        cout << "YELLOW = " << YELLOW << endl;
        cout << "GREEN = " << GREEN << endl;
    }

    return 0;
}