// compile: g++ multidimensional_3d.cpp -o multidimensional_3d.exe
// run: ./multidimensional_3d.exe

#include <iostream>
using namespace std;

int main()
{
    // Declaring and initializing a 3D array
    // Structure: 2 blocks, 3 rows, 2 columns
    int myCube[2][3][2] = {
        {// Block 0
         {10, 20},
         {30, 40},
         {50, 60}},
        {// Block 1
         {70, 80},
         {90, 100},
         {110, 120}}};

    // Use three nested loops to access and display each component
    for (int block = 0; block < 2; block++)
    {
        cout << "Block " << block << ":" << endl;
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 2; col++)
            {
                // Accessing the component using its three indices
                cout << myCube[block][row][col] << " ";
            }
            cout << endl; // New line after each row
        }
        cout << endl; // Extra space after each block
    }

    return 0;
}