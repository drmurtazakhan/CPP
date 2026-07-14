// compile: g++ enum_samevaluesTwoblocks.cpp -o enum_samevaluesTwoblocks.exe
// run: ./enum_samevaluesTwoblocks.exe

// This program demonstrates that two blocks of code can have enumerators with the same name
#include <iostream>

int main()
{
    bool condition = false; // Change this to true or false to test both blocks

    if (condition)
    {
        // Block A
        enum LocalStatus
        {
            PENDING,
            SUCCESS,
            FAILED
        };
        LocalStatus s = SUCCESS;
        std::cout << "Block A Success code: " << s << "\n";
    }
    else
    {
        // Block B
        // This is perfectly fine; it does not conflict with Block A
        enum GlobalStatus
        {
            OK,
            FAILED,
            SUCCESS
        };
        GlobalStatus s = SUCCESS;
        std::cout << "Block B Success code: " << s << "\n";
    }

    // CRITICAL: Neither 'PENDING' nor 'TIMEOUT' are accessible here.
    return 0;
}