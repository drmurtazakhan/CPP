// compile: g++  typedef_2d_array.cpp -o typedef_2d_array.exe
// run: ./typedef_2d_array.exe
/*
 * Purpose:
 *   - Demonstrate how to use typedef to declare
 *     a two-dimensional array.
 */

#include <iostream>

using namespace std;

// Define the size of the 2D array
const int NUMBER_OF_ROWS = 3;
const int NUMBER_OF_COLUMNS = 4;

// Create a new data type named tableType
// tableType represents a 3 x 4 integer array
typedef int tableType[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];

int main()
{
    // Declare a 2D array using the new type
    tableType matrix;

    // Store values in the array
    int value = 1;

    for (int row = 0; row < NUMBER_OF_ROWS; row++)
    {
        for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
        {
            matrix[row][col] = value++;
        }
    }

    // Display the contents of the array
    cout << "Contents of matrix:" << endl;

    for (int row = 0; row < NUMBER_OF_ROWS; row++)
    {
        for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
        {
            cout << matrix[row][col] << "\t";
        }
        cout << endl;
    }

    return 0;
}