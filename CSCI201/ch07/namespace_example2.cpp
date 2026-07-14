// compile: g++ namespace_example2.cpp -o namespace_example2.exe
// run: ./namespace_example2.exe

#include <iostream>

// Defining the namespace with only variables
namespace globalType
{
    const int N = 10;
    const double RATE = 7.50;
    int count = 0;
}

int main()
{
    // ------------------------------------------------------------------------
    // APPROACH 1: WITHOUT the "using" statement (Requires Scope Resolution ::)
    // ------------------------------------------------------------------------
    std::cout << "--- Accessing WITHOUT 'using' ---" << "\n";

    // We must use the 'globalType::' prefix every single time
    std::cout << "N: " << globalType::N << "\n";
    std::cout << "RATE: " << globalType::RATE << "\n";

    globalType::count = 5;
    std::cout << "Count: " << globalType::count << "\n\n";

    // ------------------------------------------------------------------------
    // APPROACH 2: WITH the "using" statement (No Scope Resolution required)
    // ------------------------------------------------------------------------
    std::cout << "--- Accessing WITH 'using' ---" << "\n";

    // This tells the compiler to look inside globalType automatically
    using namespace globalType;

    // Now we can use the variables directly without 'globalType::'
    std::cout << "N: " << N << "\n";
    std::cout << "RATE: " << RATE << "\n";

    count = 12;
    std::cout << "Count: " << count << "\n";

    return 0;
}