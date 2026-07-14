// compile: g++ test_sizetype_npos.cpp -o test_sizetype_npos.exe
// run: ./test_sizetype_npos.exe

#include <iostream>
#include <string>

int main()
{
    std::string text = "Hello, welcome to C++ programming!";

    // ---------------------------------------------------------
    // 1. Searching for "welcome"
    // ---------------------------------------------------------
    std::string::size_type pos1 = text.find("welcome");

    // Using the '==' operator and an if-else block
    if (pos1 == std::string::npos)
    {
        std::cout << "'welcome' was not found in the string.\n";
    }
    else
    {
        std::cout << "'welcome' was found at index position: " << pos1 << "\n";
    }

    // ---------------------------------------------------------
    // 2. Searching for "Java"
    // ---------------------------------------------------------
    std::string::size_type pos2 = text.find("Java");

    // Using the exact same '==' operator and an if-else block
    if (pos2 == std::string::npos)
    {
        std::cout << "'Java' was not found (returned string::npos).\n";
    }
    else
    {
        std::cout << "'Java' was found at index position: " << pos2 << "\n";
    }

    return 0;
}