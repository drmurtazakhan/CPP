/* Program name: main.cpp
   Author: Murtaza Ali Khan
   Date last updated: 3/13/2026
   Purpose: Driver program to test the YarnSkein class. It handles user input,
            validates basic data types, and catches exceptions thrown by the class.
*/

// to compile: g++ yarn_test.cpp yarn.cpp -o yarn_test
// to run: ./yarn_test < input.txt

#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
#include "yarn.h"

// Prototype for a helper function to clear the input buffer on failure
void resetStream();

int main() {
    std::string strandWeight, color, fibType;
    double skeinWeight, length, hooksize, needlesize;

    std::cout << "Welcome to the yarn creator!" << std::endl;

    // 1. Get and validate Strand Weight
    // The driver checks against the static map in the class before proceeding [cite: 21]
    std::cout << "Please start by entering the yarn strand weight. \n(Available: lace, super fine, fine, medium, bulky, super bulky, and jumbo):" << std::endl;
    std::cin >> std::ws;
    std::getline(std::cin, strandWeight);
    
    // Normalize input to uppercase to match the internal map keys
    std::string upperWeight = strandWeight;
    std::transform(upperWeight.begin(), upperWeight.end(), upperWeight.begin(), ::toupper);

    while (!YarnSkein::strToWeight.count(upperWeight)) {
        if (std::cin.eof()) {
            std::cout << "Input ended unexpectedly. Check weight maps/enums." << std::endl;
            return 1;
        }
        std::cout << "Invalid weight. Please try again: ";
        std::getline(std::cin, strandWeight);
        upperWeight = strandWeight;
        std::transform(upperWeight.begin(), upperWeight.end(), upperWeight.begin(), ::toupper);
    }

    // 2. Get basic string data
    std::cout << "Now enter the color: ";
    std::cin >> std::ws;
    std::getline(std::cin, color);

    // 3. Get and validate numeric data (Length)
    std::cout << "How long is the yarn in meters? ";
    while (!(std::cin >> length) || length < 0) {
        if (std::cin.eof()) return 1;
        resetStream();
        std::cout << "Invalid input. Length must be positive: ";
    }

    // 4. Get Fiber types
    // Note: This is a CSV string (e.g., "cotton, bamboo") that the class will parse
    std::cout << "What is the fiber made of? (e.g., cotton, bamboo, acrylic, silk, wool): " << std::endl;
    std::cin >> std::ws;
    std::getline(std::cin, fibType);

    // 5. Get and validate remaining numeric data
    std::cout << "How heavy is the skein in grams? ";
    while (!(std::cin >> skeinWeight) || skeinWeight < 0) {
        if (std::cin.eof()) return 1;
        resetStream();
        std::cout << "Invalid weight. Enter a positive number: ";
    }

    std::cout << "What is the recommended knitting needle size? ";
    while (!(std::cin >> needlesize) || needlesize < 0) {
        if (std::cin.eof()) return 1;
        resetStream();
        std::cout << "Invalid size. Enter a positive number: ";
    }

    std::cout << "What is the recommended crochet hook size? ";
    while (!(std::cin >> hooksize) || hooksize < 0) {
        if (std::cin.eof()) return 1;
        resetStream();
        std::cout << "Invalid size. Enter a positive number: ";
    }

    // 6. Instantiate the class inside a try-catch block
    // The class throws invalid_argument if inner parsing fails [cite: 19, 20]
    try {
        YarnSkein myYarn(strandWeight, color, length, fibType, skeinWeight, needlesize, hooksize);
        
        std::cout << "\n--- Yarn Created Successfully ---" << std::endl;
        std::cout << "Weight Category: " << myYarn.getStrandWeightName() << std::endl;
        std::cout << "Color:           " << myYarn.getColor() << std::endl;
        std::cout << "Fibers:          " << myYarn.getFiberList() << std::endl;
        std::cout << "Length:          " << myYarn.getLength() << "m" << std::endl;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Error creating yarn: " << e.what() << std::endl;
    }

    return 0;
}

/**
 * Helper to clean up std::cin if a user enters text instead of a number.
 */
void resetStream() {
    std::cin.clear(); // Reset error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
}