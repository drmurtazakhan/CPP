// compile: g++ fig2_5.cpp -o fig2_5.exe
// run: ./fig2_5.exe
#include <iostream>

int main()
{
    // Step 1: Declare variables and get values from the user
    double gallons_used, starting_mileage, ending_mileage;

    std::cout << "Enter gallons used: ";
    std::cin >> gallons_used;

    std::cout << "Enter starting mileage: ";
    std::cin >> starting_mileage;

    std::cout << "Enter ending mileage: ";
    std::cin >> ending_mileage;

    // Step 2: Calculate the distance driven
    double distance_driven = ending_mileage - starting_mileage;

    // Step 3: Calculate the average miles per gallon
    double average_miles_per_gallon = distance_driven / gallons_used;

    // Step 4: Print the value of average miles per gallon
    std::cout << "Average miles per gallon: " << average_miles_per_gallon << std::endl;

    // Step 5 & 6: Conditional check for good gas mileage
    if (average_miles_per_gallon > 25.0)
    {
        std::cout << "You are getting good gas mileage" << std::endl;
    }
    // Step 7: Else path if mileage is 25.0 or less
    else
    {
        std::cout << "You are NOT getting good gas mileage" << std::endl;
    }

    // Step 8: Stop program execution
    return 0;
}