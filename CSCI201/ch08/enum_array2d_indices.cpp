// compile: g++ enum_array2d_indices.cpp -o enum_array2d_indices.exe
// run: ./enum_array2d_indices.exe

#include <iostream>
using namespace std;

// Define row and column sizes
const int NUMBER_OF_ROWS = 6;
const int NUMBER_OF_COLUMNS = 5;

// Enums assign sequential integer values starting at 0:
// GM=0, FORD=1, TOYOTA=2, BMW=3, NISSAN=4, VOLVO=5
enum carType
{
    GM,
    FORD,
    TOYOTA,
    BMW,
    NISSAN,
    VOLVO
};

// RED=0, BROWN=1, BLACK=2, WHITE=3, GRAY=4
enum colorType
{
    RED,
    BROWN,
    BLACK,
    WHITE,
    GRAY
};

int main()
{
    // Declare 2D array matching the size of the enums
    int inStock[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = {0};

    // Use enum values as readable indices instead of plain numbers
    inStock[TOYOTA][RED] = 15; // Equivalent to inStock[2][0] = 15
    inStock[BMW][WHITE] = 8;   // Equivalent to inStock[3][3] = 8

    // Access elements using enum constants
    cout << "Red Toyotas in stock: " << inStock[TOYOTA][RED] << endl;
    cout << "White BMWs in stock: " << inStock[BMW][WHITE] << endl;

    return 0;
}