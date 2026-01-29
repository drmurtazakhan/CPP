#include <iostream>

using namespace std;

int main() {
    char nextChar;
    cout << "Enter a sentence ending with a period (e.g., 'Hello world.'):\n";

    cout << "Processing input...\n";

    while (cin.get(nextChar)) { // Read one character at a time from standard input
        // Check if it's a period, indicating the end of the sentence
        if (nextChar == '.') {
            cout << "End of sentence detected!\n";
            break;
        }

        // Ignore any spaces
        if (nextChar == ' ') {
            continue;
        }

        // Display the character if it's not a space or period
        cout << "Read character: " << nextChar << '\n';
    }

    return 0;
}
