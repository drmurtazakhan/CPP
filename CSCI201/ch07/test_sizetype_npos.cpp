// compile: g++ test_sizetype_npos.cpp -o test_sizetype_npos.exe
// run: ./test_sizetype_npos.exe

#include <iostream>
#include <string>

int main()
{
    std::string text = "Hello, welcome to C++ programming!";

    // 1. Using string::size_type to store the position index
    // We search for the word "welcome" using the find() function
    std::string::size_type position = text.find("welcome");

    // 2. Checking if the word was found by comparing it to string::npos
    if (position != std::string::npos)
    {
        std::cout << "'welcome' found at index position: " << position << "\n";
    }
    else
    {
        std::cout << "'welcome' was not found in the string.\n";
    }

    // 3. Another search that will fail to show how npos acts as "not found"
    std::string::size_type failPosition = text.find("Java");

    if (failPosition == std::string::npos)
    {
        std::cout << "'Java' was not found (returned string::npos).\n";
    }

    return 0;
}