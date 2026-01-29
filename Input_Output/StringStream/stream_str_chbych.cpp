#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string input;
    cout << "Enter a sentence ending with a period (e.g., 'Hello world.'):\n";
    getline(cin, input);

    // Create a string stream object to process the input string character by character
    istringstream iss(input);
    char nextChar;

    cout << "Processing input...\n";

    while (iss) {
        // Use peek() to preview the next character without extracting it
        nextChar = iss.peek();

        // Check if it's a period, indicating the end of the sentence
        if (nextChar == '.') {
            cout << "End of sentence detected!\n";
            break;
        }

        // Ignore any spaces
        if (nextChar == ' ') {
            iss.ignore(); // Move past the space
            continue;
        }

        // Extract and display the character if it's not a space or period
        char extractedChar;
        iss >> extractedChar;
        cout << "Read character: " << extractedChar << '\n';
    }

    return 0;
}
