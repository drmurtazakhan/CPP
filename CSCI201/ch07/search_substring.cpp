// compile: g++ search_substring.cpp -o search_substring.exe
// run: ./search_substring.exe

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text = "Hello, welcome to C++ programming!";

    // ---------------------------------------------------------
    // 1. Searching for "welcome"
    // ---------------------------------------------------------
    // Cast the returned position to a simple int type.
    // If not found, string::find() returns a value that casts to -1 in signed int.
    int pos1 = text.find("welcome");

    if (pos1 == -1)
    {
        cout << "'welcome' was not found in the string.\n";
    }
    else
    {
        cout << "'welcome' was found at index position: " << pos1 << "\n";
    }

    // ---------------------------------------------------------
    // 2. Searching for "Java"
    // ---------------------------------------------------------
    int pos2 = text.find("Java");

    if (pos2 == -1)
    {
        cout << "'Java' was not found in the string.\n";
    }
    else
    {
        cout << "'Java' was found at index position: " << pos2 << "\n";
    }

    return 0;
}