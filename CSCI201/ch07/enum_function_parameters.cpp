// compile: g++ enum_function_parameters.cpp -o enum_function_parameters.exe
// run: ./enum_function_parameters.exe

// Demonstrates:
// 1. Passing an enumeration by value.
// 2. Passing an enumeration by reference.
// 3. Returning an enumeration value from a function.

#include <iostream>
using namespace std;

enum Color
{
    RED,
    GREEN,
    BLUE
};

// color1 is passed by value.
// color2 is passed by reference.
// The function swaps their values and returns the new value of color1.
Color swapColors(Color color1, Color &color2)
{
    Color temp = color1;
    color1 = color2;
    color2 = temp;

    return color1;
}

int main()
{
    Color color1 = RED;
    Color color2 = GREEN;

    cout << "Before function call:" << endl;
    cout << "color1 = " << color1 << endl;
    cout << "color2 = " << color2 << endl;

    color1 = swapColors(color1, color2);

    cout << "\nAfter function call:" << endl;
    cout << "color1 = " << color1 << endl;
    cout << "color2 = " << color2 << endl;

    return 0;
}