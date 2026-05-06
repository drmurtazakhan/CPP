
// File: main.cpp
// Compile: g++ main.cpp Blockchain.cpp -o main
// Run: .\main

#include <iostream>
#include <fstream>
#include "Blockchain.h"

using namespace std;

int main() {
    Blockchain bc;

    ifstream file("input1.txt");

    if (!file) {
        cout << "Error opening input1.txt\n";
        return 1;
    }

    string line;

    // Insert messages
    while (getline(file, line)) {
        bc.insert(line);
    }

    file.close();

    // Display
    bc.display();

    // Validate
    cout << "\nValidating chain...\n";
    if (bc.validateChain())
        cout << "Blockchain is VALID\n";
    else
        cout << "Blockchain is INVALID\n";

    // Hack a block
    cout << "\nHacking block #1...\n";
    bc.hackBlock(1, "Tampered Data");

    // Display again
    bc.display();

    // Re-validate
    cout << "\nRe-validating chain...\n";
    if (bc.validateChain())
        cout << "Blockchain is VALID\n";
    else
        cout << "Blockchain is INVALID\n";

    return 0;
}