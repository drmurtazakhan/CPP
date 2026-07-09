// compile: g++ fig2_13.cpp -o fig2_13.exe
// run: ./fig2_13.exe
#include <iostream>
#include <string>

int main()
{
    // Step 1: Get values for NUMBER, T1...T4, and N1...N4
    int NUMBER;

    // Using arrays of size 5 to use 1-based indexing (ignoring index 0)
    int T[5] = {0, 101, 102, 103, 104};
    std::string N[5] = {"", "Alice", "Bob", "Charlie", "Diana"};

    std::cout << "Enter the NUMBER to search for: ";
    std::cin >> NUMBER;

    // Step 2: Set the value of i to 1 and set the value of Found to NO
    int i = 1;
    std::string Found = "NO";

    // Step 3: While both (Found = NO) and (i <= 4) do Steps 4 through 7
    while (Found == "NO" && i <= 4)
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

    // Step 8: If (Found = NO) then
    if (Found == "NO")
    {
        // Step 9: Print the message 'Sorry, this number is not in the directory'
        std::cout << "Sorry, this number is not in the directory" << std::endl;
    }

    // Step 10: Stop
    return 0;
}