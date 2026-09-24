// compile: g++ catch_all_demo.cpp -o catch_all_demo.exe
// run: ./catch_all_demo.exe

// catch_all_demo.cpp
#include <iostream>
#include <string>

void testException(int choice)
{
    try
    {
        if (choice == 1)
        {
            throw 404; // Throws an integer
        }
        else if (choice == 2)
        {
            throw std::string("Disk full error"); // Throws a string
        }
        else if (choice == 3)
        {
            throw 3.14; // Throws a double
        }
        else
        {
            // No exception thrown
            std::cout << "No exception thrown. Execution completed normally." << std::endl;
        }
    }
    catch (int e)
    {
        // Specific handler: catches ONLY integer exceptions
        std::cout << "Caught a specific integer exception: " << e << std::endl;
    }
    catch (...)
    {
        // Catch-all handler: the '...' catches ANY exception type not handled above
        std::cout << "Caught an unexpected exception of unknown type!" << std::endl;
    }
}

int main()
{
    std::cout << "--- Test 1 (Specific catch) ---" << std::endl;
    testException(1); // Triggers 'catch (int e)'

    std::cout << "\n--- Test 2 (Ellipses catch) ---" << std::endl;
    testException(2); // Triggers 'catch (...)' with a string

    std::cout << "\n--- Test 3 (Ellipses catch) ---" << std::endl;
    testException(3); // Triggers 'catch (...)' with a double

    std::cout << "\n--- Test 4 (Normal execution) ---" << std::endl;
    testException(4); // Executes the final else branch (no throw)

    return 0;
}