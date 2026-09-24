// This program will also produce a compilation error because RED and GREEN have already been declared at the global scope.
// compile: g++ enum_global_scope.cpp -o enum_global_scope.exe
#include <iostream>
using namespace std;

// First enumeration is declared at global scope.
enum Color
{
    RED,
    GREEN,
    BLUE
};

// Second enumeration is also declared at global scope.
enum TrafficLight
{
    RED, // ERROR: RED was already declared at global scope
    YELLOW,
    GREEN // ERROR: GREEN was already declared at global scope
};

int main()
{
    return 0;
}