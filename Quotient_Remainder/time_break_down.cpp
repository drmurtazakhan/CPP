#include <iostream>
using namespace std;
int main()
{
    // Define constants for seconds in an hour and a minute
    const unsigned int SECONDS_IN_A_MINUTE = 60;
    const unsigned int MINUTES_IN_AN_HOUR = 60;
    const unsigned int SECONDS_IN_AN_HOUR = SECONDS_IN_A_MINUTE * MINUTES_IN_AN_HOUR;    

    // Declare variables to store hours, minutes, seconds, and remaining seconds
    unsigned int hours, minutes, seconds, remainingSeconds; 

    // Input: Total seconds to convert
    unsigned long totalSeconds = 3800;

    hours = totalSeconds / SECONDS_IN_AN_HOUR;            // Calculate hours
    remainingSeconds = totalSeconds % SECONDS_IN_AN_HOUR; // remaining seconds after hours

    minutes = remainingSeconds / SECONDS_IN_A_MINUTE; // Calculate minutes
    seconds = remainingSeconds % SECONDS_IN_A_MINUTE; // remaining seconds after minutes

    cout << "Total Seconds: " << totalSeconds << endl;
    cout << "Hours: " << hours << endl;
    cout << "Minutes: " << minutes << endl;
    cout << "Seconds: " << seconds << endl;

    return 0;
}

