// Enum_TrafficLight.cpp
// Compile with: g++ Enum_TrafficLight.cpp -o Enum_TrafficLight.exe
// Run: ./Enum_TrafficLight.exe

#include <iostream>
using namespace std;

// 1. Defining the Enumeration
// This creates a brand new simple data type called 'TrafficLight'
enum TrafficLight
{
    RED,    // Assigned the integer value 0 behind the scenes
    YELLOW, // Assigned the integer value 1
    GREEN   // Assigned the integer value 2
};

int main()
{
    // 2. Creating a variable of our new data type
    // Just like 'int age = 5;', we do 'TrafficLight currentSignal = RED;'
    TrafficLight currentSignal = RED;

    // 3. Using it in a check
    if (currentSignal == RED)
    {
        cout << "Stop! The light is red." << endl;
    }
    else if (currentSignal == GREEN)
    {
        cout << "Go! The light is green." << endl;
    }

    // Note: If you print the variable directly, C++ prints its underlying integer!
    cout << "The integer value of currentSignal is: " << currentSignal << endl;

    return 0;
}