#include <iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
using namespace std;

int main() {
    // 1. Seed the random number generator so numbers are different every time
    srand(time(0));

    // 2. Declare 'board' as an array of 4 pointers
    int *board[4];

    // 3. Create the rows (6 columns each)
    for (int row = 0; row < 4; row++) {
        board[row] = new int[6];
    }

    // 4. Fill the array with random numbers (1 to 100)
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 6; col++) {
            board[row][col] = rand() % 100 + 1; 
        }
    }

    // 5. Print the array in a grid format
    cout << "--- 4x6 Dynamic Board Contents ---" << endl;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 6; col++) {
            cout << board[row][col] << "\t"; // \t adds a tab space
        }
        cout << endl; // New line after each row
    }

    // 6. Cleanup
    for (int row = 0; row < 4; row++) {
        delete[] board[row];
    }

    return 0;
}