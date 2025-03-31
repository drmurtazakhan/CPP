#include <iostream>
#include <limits>  // Required for numeric_limits
using namespace std;

int main() {
    long score;

    cout << "Please enter a score: ";
    cin >> score;

    // Loop to handle invalid input
    while (cin.fail() || score < 0) {
        if (cin.fail()) {
            cin.clear(); // Clears the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the invalid input
            cerr << "Invalid input. Please enter an integer value." << endl;
        } else {
            cerr << "Invalid score. Score must be non-negative." << endl;
        }
        
        // Re-prompt the user
        cout << "Please enter a valid score: ";
        cin >> score;
    }

    cout << "Valid score entered: " << score << endl;

    return 0;
}
