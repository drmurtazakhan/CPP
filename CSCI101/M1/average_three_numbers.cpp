#include <iostream>
using namespace std;

int main()
{
    // Declare variables to store the four numbers
    double num1, num2, num3, num4;

    // Ask the user for input
    cout << "Enter four numbers: ";
    cin >> num1 >> num2 >> num3 >> num4;

    // Calculate the average
    double average = (num1 + num2 + num3 + num4) / 4.0;

    // Display the result
    cout << "Average = " << average << endl;

    return 0;
}
