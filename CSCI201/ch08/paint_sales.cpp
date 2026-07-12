// File name: paint_sales.cpp
// compile: g++ paint_sales.cpp -o paint_sales.exe
// run: ./paint_sales.exe
#include <iostream>

using namespace std;

int main()
{
    // Define an enumeration for different paint types
    enum paintType
    {
        GREEN,
        RED,
        BLUE,
        BROWN,
        WHITE,
        ORANGE,
        YELLOW
    };

    // Declare an array of 7 doubles to store sales for each paint type
    double paintSale[7];

    // Declare a variable of type paintType to use as an index
    paintType paint;

    // Use a for loop to initialize each element in the array to 0.0.
    // The loop iterates through each enum value.
    for (paint = GREEN; paint <= YELLOW; paint = static_cast<paintType>(paint + 1))
    {
        paintSale[paint] = 0.0;
    }

    // Update the sales figure for RED paint specifically
    paintSale[RED] = paintSale[RED] + 75.69;

    // Output the result for verification
    cout << "Sales for RED paint: " << paintSale[RED] << endl;

    return 0;
}