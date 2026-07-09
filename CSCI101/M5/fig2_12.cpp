/*
Warning: This code contains a logical error in the while loop condition.
loop may run indefinitely if the number is not found.
*/

// compile: g++ fig2_12.cpp -o fig2_12.exe
// run: ./fig2_12.exe
#include <iostream>
#include <string>

int main()
{
    // Step 1: Get values for NUMBER, T1...T4, and N1...N4
    int NUMBER;

    // Arrays sized to 5 so we can use 1-based indexing (ignoring index 0)
    int T[5] = {0, 101, 102, 103, 104};
    std::string N[5] = {"", "Alice", "Bob", "Charlie", "Diana"};

    std::cout << "Enter the NUMBER to search for: ";
    std::cin >> NUMBER;

    // Step 2: Set the value of i to 1 and set the value of Found to NO
    int i = 1;
    std::string Found = "NO";

    // Step 3: While (Found = NO) do Steps 4 through 7
    while (Found == "NO")
    {

        // Step 4: If NUMBER is equal to the ith number on the list, Ti, then
        if (NUMBER == T[i])
        {
            // Step 5: Print the name of the corresponding person, Ni
            std::cout << N[i] << std::endl;

            // Step 6: Set the value of Found to YES
            Found = "YES";
        }
        // Else (NUMBER is not equal to Ti)
        else
        {
            // Step 7: Add 1 to the value of i
            i = i + 1;
        }
    }

    // Step 8: Stop
    return 0;
}