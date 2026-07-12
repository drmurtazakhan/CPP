// file: test1_string_array.cpp
// compile: g++ test1_string_array.cpp -o test1_string_array.exe
// run: ./string_array.exe

/*
 * Purpose:
 *   - Demonstrate an array of strings.
 *   - Initialize the array during declaration.
 *   - Display the contents using a loop.
 */

#include <iostream>
#include <string> // Required for the string type
#include <vector> // Often used instead of raw arrays

using namespace std;

int main()
{
    // A vector of string objects is much more flexible than a 2D char array
    string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    for (int i = 0; i < 12; i++)
    {
        cout << "Month " << i + 1 << ": " << months[i] << endl;
    }

    return 0;
}