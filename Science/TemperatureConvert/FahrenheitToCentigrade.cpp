# include <iostream> // Include the iostream library for input and output
using namespace std;

int main()
{
    float fahrenheit; // Declare variable to store temperature in Fahrenheit
    float centigrade; // Declare variable to store temperature in Centigrade

    cout << "Enter temperatue in Fahrenheit: "; // Prompt user to enter temperature in Fahrenheit
    cin >> fahrenheit; // Read temperature in Fahrenheit from user

    centigrade = (fahrenheit - 32) * 5 / 9; // Convert temperature from Fahrenheit to Centigrade

    cout << "Equaivalent temperature in Centigrade is: " << centigrade << endl;
    
    return 0; // Indicate successful program termination
}