// The user program that uses the class clockType
//  testClockClass.cpp
//  compile: g++ testClockClass.cpp clockTypeImp.cpp -o testClockClass.exe
//  run: ./testClockClass.exe

#include <iostream>
#include "clockType.h"

using namespace std;

int main()
{
     clockType myClock;
     clockType yourClock;

     int hours;
     int minutes;
     int seconds;

     // Set the time of myClock
     myClock.setTime(5, 4, 30); // Line 1

     cout << "myClock: ";
     myClock.printTime();
     cout << endl;

     cout << "yourClock: ";
     yourClock.printTime(); // print the time of yourClock
     cout << endl;

     // Set the time of yourClock
     yourClock.setTime(5, 45, 16);

     cout << "After setting, yourClock: ";
     yourClock.printTime(); // print the time of yourClock
     cout << endl;

     // Compare myClock and yourClock
     if (myClock.equalTime(yourClock))
          cout << "Both times are equal."
               << endl;
     else
          cout << "The two times are not equal."
               << endl;

     cout << "Line 16: Enter the hours, minutes, and "
          << "seconds e.g., 7 35 45: ";
     cin >> hours >> minutes >> seconds;
     cout << endl;

     // Set the time of myClock using the value of the
     // variables hours, minutes, and seconds
     myClock.setTime(hours, minutes, seconds);

     cout << "Line 20: New myClock: ";
     myClock.printTime(); // print the time of myClock
     cout << endl;

     // Increment the time of myClock by one second
     myClock.incrementSeconds();

     cout << "Line 24: After incrementing myClock by "
          << "one second, myClock: ";
     myClock.printTime(); // print the time of myClock
     cout << endl;

     // Retrieve the hours, minutes, and seconds of the
     // object myClock
     myClock.getTime(hours, minutes, seconds);

     // Output the value of hours, minutes, and seconds
     cout << "hours = " << hours
          << ", minutes = " << minutes
          << ", seconds = " << seconds << endl;

     clockType ourClock(23, 59, 59);
     cout << "ourClock: ";
     ourClock.printTime();

     return 0;
} // end main
