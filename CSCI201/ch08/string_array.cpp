// compile: g++ string_array.cpp -o string_array.exe
// run: ./string_array.exe
/*
 * Purpose:
 *   - Demonstrate basic operations on an array of strings.
 *   - Operations include:
 *       1. Assignment
 *       2. Display
 *       3. Comparison
 *       4. Input
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Declare and initialize an array of strings
    string names[5] =
        {
            "Alice",
            "Bob",
            "Charlie",
            "David",
            "Emma"
        };

    // Display the original array
    cout << "Original names:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << names[i] << endl;
    }

    cout << endl;

    // 1. Assignment
    // Change the second name (index 1)
    names[1] = "John";

    // 2. Display one element
    cout << "After assignment:" << endl;
    cout << "names[1] = " << names[1] << endl;

    cout << endl;

    // 3. Comparison
    if (names[0] == "Alice")
    {
        cout << "names[0] is Alice." << endl;
    }
    else
    {
        cout << "names[0] is not Alice." << endl;
    }

    cout << endl;

    // 4. Input
    cout << "Enter a new name for names[2]: ";
    cin >> names[2];

    cout << endl;

    // Display the updated array
    cout << "Updated names:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << names[i] << endl;
    }

    return 0;
}