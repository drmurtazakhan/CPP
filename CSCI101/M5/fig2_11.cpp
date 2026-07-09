// compile: g++ fig2_11.cpp -o fig2_11.exe
// run: ./fig2_11.exe
#include <iostream>
#include <string>

int main()
{
    // Step 1: Get values for NUMBER, T1...T4, and N1...N4
    int NUMBER;

    // T variables represent the target keys we are searching for
    int T1 = 101, T2 = 102, T3 = 103, T4 = 104;

    // N variables represent the corresponding values/names attached to those keys
    std::string N1 = "Alice", N2 = "Bob", N3 = "Charlie", N4 = "Diana";

    std::cout << "Enter the NUMBER to search for: ";
    std::cin >> NUMBER;

    // Step 2: If NUMBER = T1 then print the value of N1
    if (NUMBER == T1)
    {
        std::cout << N1 << std::endl;
    }

    // Step 3: If NUMBER = T2 then print the value of N2
    if (NUMBER == T2)
    {
        std::cout << N2 << std::endl;
    }

    // Step 4: If NUMBER = T3 then print the value of N3
    if (NUMBER == T3)
    {
        std::cout << N3 << std::endl;
    }

    // (Representing the shortened end of the sequence)
    // If NUMBER = T4 then print the value of N4
    if (NUMBER == T4)
    {
        std::cout << N4 << std::endl;
    }

    // Step 10,002: Stop
    return 0;
}