// File name: Exp_8_3.cpp
// compile: g++ Exp_8_3.cpp -o Exp_8_3.exe
// run: ./Exp_8_3.exe

// This program demonstrates various array processing techniques:
// initializing, reading, printing, calculating sum/average,
// and finding the largest element.
#include <iostream>

using namespace std;

int main()
{
    // Declaration of array and variables
    double sales[10];
    int index;
    double largestSale, sum, average;
    int maxIndex;

    // a. Initializing an array to 0.0
    for (index = 0; index < 10; index++)
        sales[index] = 0.0;

    // b. Reading data into the array from the keyboard
    cout << "Enter 10 sales figures: ";
    for (index = 0; index < 10; index++)
        cin >> sales[index];

    // c. Printing the array to the screen
    cout << "Sales figures: ";
    for (index = 0; index < 10; index++)
        cout << sales[index] << " ";
    cout << endl;

    // d. Finding the sum and average
    sum = 0;
    for (index = 0; index < 10; index++)
        sum = sum + sales[index];

    average = sum / 10;
    cout << "Total sum: " << sum << endl;
    cout << "Average sale: " << average << endl;

    // e. Finding the largest element in the array
    // We assume the first element is the largest initially
    maxIndex = 0;

    // Compare current max with subsequent elements
    for (index = 1; index < 10; index++)
    {
        if (sales[maxIndex] < sales[index])
        {
            maxIndex = index; // Update index to the new largest element
        }
    }

    largestSale = sales[maxIndex];
    cout << "The largest sale amount is " << largestSale
         << " at index " << maxIndex << endl;

    return 0;
}