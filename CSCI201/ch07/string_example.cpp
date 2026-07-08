// File Name: string_example.cpp
// Compile: g++ string_example.cpp -o string_example.exe
// Run: ./string_example.exe

// This program demonstrates the string data type
// and some commonly used string functions.

#include <iostream>
#include <string> // Required for string type

using namespace std;

int main()
{
    // Declare and initialize a string variable.
    string name = "Alice";

    // Display the original string.
    cout << "Name: " << name << endl;

    // length() returns the number of characters.
    cout << "Length: " << name.length() << endl;

    // at(index) returns the character at the specified position.
    cout << "First character: " << name.at(0) << endl;

    // append() adds text to the end of the string.
    name.append(" Smith");
    cout << "After append: " << name << endl;

    // substr(start, length) returns part of the string.
    cout << "Substring: " << name.substr(0, 5) << endl;

    // find() returns the position of a character or substring.
    cout << "Position of 'S': " << name.find("S") << endl;

    // erase(start, length) removes characters.
    name.erase(5, 6);
    cout << "After erase: " << name << endl;

    return 0;
}