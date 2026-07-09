// compile: g++ fig2_10.cpp -o fig2_10.exe
// run: ./fig2_10.exe
#include <iostream>

int main()
{
    // 1. Get values for a and b
    int a, b;
    std::cout << "Enter value for a: ";
    std::cin >> a;
    std::cout << "Enter value for b: ";
    std::cin >> b;

    // Initialize the product variable
    int product = 0;

    // 2. If (either a = 0 or b = 0) then
    if (a == 0 || b == 0)
    {
        // Set the value of product to 0
        product = 0;
    }
    // Else
    else
    {
        // Set the value of count to 0
        int count = 0;

        // Set the value of product to 0
        product = 0;

        // While (count < b) do
        while (count < b)
        {
            // Set the value of product to (product + a)
            product = product + a;

            // Set the value of count to (count + 1)
            count = count + 1;
        } // End of loop
    }

    // 3. Print the value of product
    std::cout << "The product is: " << product << std::endl;

    // 4. Stop
    return 0;
}