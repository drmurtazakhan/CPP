// compile: g++ fig2_7.cpp -o fig2_7.exe
// run: ./fig2_7.exe
#include <iostream>
#include <string>

int main()
{
    // Step 1: Initialize the response variable to "Yes"
    std::string response = "Yes";

    // Step 2: Loop while response is equal to "Yes"
    while (response == "Yes" || response == "yes")
    {

        // Step 3: Declare variables and get input values from the user
        double gallons_used, starting_mileage, ending_mileage;

        std::cout << "\nEnter gallons used: ";
        std::cin >> gallons_used;

        std::cout << "Enter starting mileage: ";
        std::cin >> starting_mileage;

        std::cout << "Enter ending mileage: ";
        std::cin >> ending_mileage;

        // Step 4: Calculate the distance driven
        double distance_driven = ending_mileage - starting_mileage;

        // Step 5: Calculate the average miles per gallon
        double average_miles_per_gallon = distance_driven / gallons_used;

        // Step 6: Print the value of average miles per gallon
        std::cout << "Average miles per gallon: " << average_miles_per_gallon << std::endl;

        // Step 7 & 8: Check if mileage is good
        if (average_miles_per_gallon > 25.0)
        {
            std::cout << "You are getting good gas mileage" << std::endl;
        }
        // Step 9: Else path if mileage is 25.0 or less
        else
        {
            std::cout << "You are NOT getting good gas mileage" << std::endl;
        }

        // Step 10: Ask the user if they want to repeat the process
        std::cout << "\nDo you want to do this again? Enter Yes or No: ";

        // Step 11: Get a new value for response from the user
        std::cin >> response;
    }

    // Step 12: Stop program execution
    std::cout << "Program stopped." << std::endl;
    return 0;
}