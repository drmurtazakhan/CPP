// This program will produce a compilation error because RED and GREEN have already been declared in the same block, i.e., block of main().
// compile: g++ enum_same_block.cpp -o enum_same_block.exe

#include <iostream>
using namespace std;

int main()
{
    // First enumeration declared inside the main() block.
    enum Color
    {
        RED,
        GREEN,
        BLUE
    };

    // Second enumeration is declared in the same block.
    enum TrafficLight
    {
        RED, // ERROR: RED was already declared in this block
        YELLOW,
        GREEN // ERROR: GREEN was already declared in this block
    };

    return 0;
}