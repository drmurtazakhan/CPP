// compile: g++ fig2_14.cpp -o fig2_14.exe
// run: ./fig2_14.exe
#include <iostream>

int main()
{
    // 1. Get a value for n, the size of the list
    int n = 5;

    // Get values for A1, A2, ..., An, the list to be searched
    // Using an array of size 6 so we can use 1-based indexing (ignoring index 0)
    int A[6] = {0, 23, 87, 45, 92, 12};

    // 2. Set the value of largest so far to A1
    int largest_so_far = A[1];

    // 3. Set the value of location to 1
    int location = 1;

    // 4. Set the value of i to 2
    int i = 2;

    // 5. While (i <= n) do
    while (i <= n)
    {

        // If Ai > largest so far then
        if (A[i] > largest_so_far)
        {
            // Set largest so far to Ai
            largest_so_far = A[i];

            // Set location to i
            location = i;
        }

        // Add 1 to the value of i
        i = i + 1;
    } // End of the loop

    // 6. Print out the values of largest so far and location
    std::cout << "Largest so far: " << largest_so_far << std::endl;
    std::cout << "Location: " << location << std::endl;

    // 7. Stop
    return 0;
}