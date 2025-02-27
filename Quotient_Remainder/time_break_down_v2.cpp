#include <iostream>
using namespace std;
int main()
{
    // Define constants for seconds in an hour and a minute
    const unsigned int SECONDS_IN_A_MINUTE = 60;
    const unsigned int MINUTES_IN_AN_HOUR = 60;
    const unsigned int SECONDS_IN_AN_HOUR = SECONDS_IN_A_MINUTE * MINUTES_IN_AN_HOUR;    

    // Declare variables to store hours, minutes, and seconds
    unsigned int hours, minutes, seconds; 

    // Input: Total seconds to convert
    unsigned long totalSeconds = 3800;

    hours = totalSeconds / SECONDS_IN_AN_HOUR;                           // Calculate hours
    minutes = (totalSeconds % SECONDS_IN_AN_HOUR) / SECONDS_IN_A_MINUTE; // Calculate minutes
    seconds = (totalSeconds % SECONDS_IN_AN_HOUR) % SECONDS_IN_A_MINUTE; // Calculate seconds

    cout << "Total Seconds: " << totalSeconds << endl;
    cout << "Hours: " << hours << endl;
    cout << "Minutes: " << minutes << endl;
    cout << "Seconds: " << seconds << endl;

    return 0;
}

