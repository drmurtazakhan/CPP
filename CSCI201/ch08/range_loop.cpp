// File name: range_loop.cpp
// compile: g++ range_loop.cpp -o range_loop.exe
// run: ./range_loop.exe

#include <iostream>

using namespace std;

int main()
{
    // Declare an array of 5 doubles and initialize it
    double list[5] = {1.5, 2.5, 3.5, 4.5, 5.5};
    double sum;

    // Initialize sum
    sum = 0;

    // Use a range-based for loop to add each element in 'list' to 'sum'
    // This reads as: "for each 'num' in 'list'"
    for (double num : list)
    {
        sum = sum + num;
    }

    // Display the calculated sum
    cout << "The total sum is: " << sum << endl;

    return 0;
}