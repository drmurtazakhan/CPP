/*
 * File name: calorie_tracker.cpp
 * This program demonstrates two methods to calculate the average
 * calories burned over a 7-day period.
 * Compile: g++ calorie_tracker.cpp -o calorie_tracker.exe
 * Run: ./calorie_tracker.exe
 */

#include <iostream>

using namespace std;

int main()
{
    // --- Method 1: Individual Variables ---
    // This approach is tedious and does not scale well.
    double d1, d2, d3, d4, d5, d6, d7;
    double sumMethod1;

    cout << "Enter calories burned for 7 days (Method 1): ";
    cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6 >> d7;

    sumMethod1 = d1 + d2 + d3 + d4 + d5 + d6 + d7;
    cout << "Average (Method 1): " << sumMethod1 / 7 << endl;

    // --- Method 2: Using a Loop ---
    // This is the efficient way to handle repeating input.
    // We only need two variables regardless of how many days we track.
    double dailyCalories;
    double sumMethod2 = 0; // Accumulator variable

    cout << "\nEnter calories burned for 7 days (Method 2): ";
    for (int i = 1; i <= 7; i++)
    {
        cin >> dailyCalories;                    // Read input into the same variable
        sumMethod2 = sumMethod2 + dailyCalories; // Add to the accumulator
    }

    cout << "Average (Method 2): " << sumMethod2 / 7 << endl;

    return 0;
}