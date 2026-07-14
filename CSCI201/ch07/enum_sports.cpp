// File Name: enum_sports.cpp
// Compile: g++ enum_sports.cpp -o enum_sports.exe
// Run: ./enum_sports.exe
// This program demonstrates enumeration type in C++.

#include <iostream>
using namespace std;

// Define an enumeration type called sports.
// Each enumerator is assigned an integer value automatically:
//
// BASKETBALL = 0
// FOOTBALL   = 1
// HOCKEY     = 2
// BASEBALL   = 3
// SOCCER     = 4
// VOLLEYBALL = 5
//
enum sports
{
    BASKETBALL,
    FOOTBALL,
    HOCKEY,
    BASEBALL,
    SOCCER,
    VOLLEYBALL
};

int main()
{
    // Declare two variables of type sports.
    sports popularSport;
    sports mySport;

    // Assign FOOTBALL to popularSport.
    popularSport = FOOTBALL;

    cout << "Popular sport value: " << popularSport << endl;

    cout << "Now Popular sport value: " << static_cast<sports>(popularSport + 1) << endl;

    cout << endl;
    cout << "List of sports:" << endl;

    // Start from BASKETBALL and continue until SOCCER.
    // static_cast<sports>(mySport + 1) converts the integer value
    // back to the enumeration type.
    //
    // Without static_cast, C++ does not automatically convert an
    // integer value to an enum type.

    for (mySport = BASKETBALL;
         mySport <= SOCCER;
         mySport = static_cast<sports>(mySport + 1))
    {
        // Display the integer value of each enumerator.
        cout << "Sport value: " << mySport << endl;
    }

    return 0;
}